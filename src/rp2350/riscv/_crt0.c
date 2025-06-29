#include <stdint.h>

#include <rp2350/clocks.h>
#include <rp2350/pll.h>
#include <rp2350/resets.h>
#include <rp2350/xosc.h>

#define RAMSIZE         (520*1024)

extern char __bss_start[RAMSIZE], __bss_end[];
extern char __data_start[RAMSIZE], __data_end[], __data_lma[RAMSIZE];

extern void main();
extern void __vector_table();

static void init_clocks();
static void init_xosc();

void RESET_Handler() {

    //init_clocks();

    // set global pointer and stack pointer
    __asm__ volatile (
            ".option push;"
            ".option norelax;"
            "la     gp, __global_pointer$;"
            ".option pop;"
            "la     sp, __stack_top"
            : /* no output */
            : /* no input */
            : /* no clobbers */);

    __asm__ volatile (
            "csrw   mtvec, %0"
            : /* no output */
            : "r" ((uint32_t)(__vector_table) | 1) /* input from register */
            : /* no clobbers */);

    // copy data section to SRAM
    char *to = __data_start;
    char *from = __data_lma;
    while (to < __data_end)
        *to++ = *from++;

    // zero out the BSS section
    to = __bss_start;
    while (to < __bss_end)
        *to++ = 0;

    main();
}

void init_clocks()
{
    clocks.clk_sys_resus_ctrl = 0;

    // initialize crystal oscillator
    init_xosc();

    // reset pll_sys
    resets.reset_set = RESETS_RESET_PLL_SYS_MASK;
    resets.reset_clr = RESETS_RESET_PLL_SYS_MASK;
    while ((resets.reset_done & RESETS_RESET_PLL_SYS_MASK) == 0) {}

    // switch glitchless mux to ref
    clocks.clk_sys_ctrl_clr = CLOCKS_CLK_SYS_CTRL_SRC_MASK;
    while (clocks.clk_sys_selected != 0x1) {}

    /* configure pll_sys to generate 150 MHz system clock
     * REFDIV:  1
     * FBDIV:   125
     * PD1:     5
     * PD2:     2 */
    pll_sys.cs = PLL_SYS_CS_REFDIV(1);
    pll_sys.fbdiv_int = PLL_SYS_FBDIV_INT(125);

    // clear main and VC0 power down bits to start PLL
    pll_sys.pwr_clr = PLL_SYS_PWR_PD_MASK | PLL_SYS_PWR_VCOPD_MASK;
    while (!((pll_sys.cs) & PLL_SYS_CS_LOCK_MASK)) {}

    pll_sys.prim = PLL_SYS_PRIM_POSTDIV1(5) | PLL_SYS_PRIM_POSTDIV2(2);
    pll_sys.pwr_clr = PLL_SYS_PWR_POSTDIVPD_MASK;

    // configure clk_sys
    clocks.clk_sys_ctrl_clr = CLOCKS_CLK_SYS_CTRL_AUXSRC_MASK;
    clocks.clk_sys_ctrl_set = CLOCKS_CLK_SYS_CTRL_SRC_MASK;
    while (clocks.clk_sys_selected != 0x1) {}
    clocks.clk_sys_div = CLOCKS_CLK_SYS_DIV_INT(1);

    // configure clk_ref (XOSC as source)
    clocks.clk_ref_ctrl_clr = CLOCKS_CLK_REF_CTRL_SRC_MASK;
    clocks.clk_ref_ctrl_set = CLOCKS_CLK_REF_CTRL_SRC(2);
    clocks.clk_ref_div = CLOCKS_CLK_REF_DIV_INT(12);
}

/* Crystal Oscillator configuration
 * 12 MHz crystal and 1 ms wait time
 * Startup delay: 12 MHz * 1 ms / 256 = 47 */
void init_xosc()
{
    xosc.ctrl = XOSC_CTRL_FREQ_RANGE(0xaa0);
    xosc.startup = XOSC_STARTUP_DELAY(47);
    xosc.ctrl |= XOSC_CTRL_ENABLE(0xfab);
    while ((xosc.status & XOSC_STATUS_STABLE_MASK) == 0) {}
}

void _entry_point() {
    RESET_Handler();
}
