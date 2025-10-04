#include <stdint.h>
#include <rp2350/clocks.h>
#include <rp2350/pll.h>
#include <rp2350/resets.h>
#include <rp2350/xosc.h>

#define RAMSIZE         (520*1024)

extern char __bss_start[RAMSIZE], __bss_end[];
extern char __data_start[RAMSIZE], __data_end[], __data_lma[RAMSIZE];

extern void main(void);
extern void __stack_top(void);
extern void __vector_table(void);

static void init_clocks(void);

void RESET_Handler(void) {
    // set global pointer and stack pointer
    __asm__ volatile (
#if 0
            ".option push;"
            ".option norelax;"
            "la     gp, __global_pointer$;"
            ".option pop;"
#endif
            "la     sp, %0"
            : /* no output */
            : "i" ((uint32_t)(__stack_top)) /* input from immediate */
            : /* no clobbers */);

    __asm__ volatile (
            "csrw   mtvec, %0"
            : /* no output */
            : "r" ((uint32_t)(__vector_table) | 1) /* input from register */
            : /* no clobbers */);
    
    init_clocks();

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

static void init_clocks(void)
{
    clocks.clk_sys_resus_ctrl = 0;

    /* Crystal Oscillator configuration
     * 12 MHz crystal and 1 ms wait time
     * Startup delay: 12 MHz * 1 ms / 256 = 47 */
    xosc.ctrl = XOSC_CTRL_FREQ_RANGE(0xaa0);
    xosc.startup = XOSC_STARTUP_DELAY(47);
    xosc.ctrl_set = XOSC_CTRL_ENABLE(0xfab);
    while ((xosc.status & XOSC_STATUS_STABLE_MASK) != XOSC_STATUS_STABLE_MASK) {}

    // reset pll_sys
    resets.reset_set = RESETS_RESET_PLL_SYS_MASK;
    resets.reset_clr = RESETS_RESET_PLL_SYS_MASK;
    while ((resets.reset_done & RESETS_RESET_PLL_SYS_MASK) != RESETS_RESET_PLL_SYS_MASK) {}

    // switch glitchless mux to ref
    clocks.clk_sys_ctrl_clr = CLOCKS_CLK_SYS_CTRL_SRC_MASK;
    while (!(clocks.clk_sys_selected)) {}

    /* configure pll_sys to generate 150 MHz system clock
     * REFDIV:  1
     * FBDIV:   125
     * PD1:     5
     * PD2:     2 */
    pll_sys.cs = PLL_CS_REFDIV(1);
    pll_sys.fbdiv_int = PLL_FBDIV_INT(125);

    // clear main and VC0 power down bits to start PLL
    pll_sys.pwr_clr = PLL_PWR_PD_MASK | PLL_PWR_VCOPD_MASK;
    while ((pll_sys.cs & PLL_CS_LOCK_MASK) != PLL_CS_LOCK_MASK) {}

    pll_sys.prim = PLL_PRIM_POSTDIV1(5) | PLL_PRIM_POSTDIV2(2);
    pll_sys.pwr_clr = PLL_PWR_POSTDIVPD_MASK;

    // reset pll_usb
    resets.reset_set = RESETS_RESET_PLL_USB_MASK;
    resets.reset_clr = RESETS_RESET_PLL_USB_MASK;
    while ((resets.reset_done & RESETS_RESET_PLL_USB_MASK) != RESETS_RESET_PLL_USB_MASK) {}

    /* configure pll_usb to generate 48 MHz peripheral clock
     * REFDIV:  1
     * FBDIV:   100
     * PD1:     5
     * PD2:     5 */
    pll_usb.cs = PLL_CS_REFDIV(1);
    pll_usb.fbdiv_int = PLL_FBDIV_INT(100);

    // clear main and VC0 power down bits to start PLL
    pll_usb.pwr_clr = PLL_PWR_PD_MASK | PLL_PWR_VCOPD_MASK;
    while ((pll_usb.cs & PLL_CS_LOCK_MASK) != PLL_CS_LOCK_MASK) {}

    pll_usb.prim = PLL_PRIM_POSTDIV1(5) | PLL_PRIM_POSTDIV2(5);
    pll_usb.pwr_clr = PLL_PWR_POSTDIVPD_MASK;

    // configure clk_sys
    clocks.clk_sys_ctrl_clr = CLOCKS_CLK_SYS_CTRL_AUXSRC_MASK;
    clocks.clk_sys_ctrl_set = CLOCKS_CLK_SYS_CTRL_SRC_MASK;
    while (clocks.clk_sys_selected == 0) {}
    clocks.clk_sys_div = CLOCKS_CLK_SYS_DIV_INT(1);
    
    // configure clk_ref (XOSC as source)
    clocks.clk_ref_ctrl_clr = CLOCKS_CLK_REF_CTRL_SRC_MASK;
    clocks.clk_ref_ctrl_set = CLOCKS_CLK_REF_CTRL_SRC(2);
    clocks.clk_ref_div = CLOCKS_CLK_REF_DIV_INT(12);

    // configure peripheral clock (PLL_USB as source)
    clocks.clk_peri_ctrl_clr = CLOCKS_CLK_PERI_CTRL_ENABLE_MASK;
    clocks.clk_peri_ctrl_set = CLOCKS_CLK_PERI_CTRL_AUXSRC(2);
    clocks.clk_peri_ctrl_set = CLOCKS_CLK_PERI_CTRL_ENABLE_MASK;
    clocks.clk_peri_div = CLOCKS_CLK_PERI_DIV_INT(1);
}
