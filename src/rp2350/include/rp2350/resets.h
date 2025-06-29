#ifndef RP2350_RESETS_H
#define RP2350_RESETS_H

#include <stdint.h>

#define _u(v)           (uint32_t)(v)
#define ALL1            _u(0xffffffff)

typedef struct {
    uint32_t reset;
    uint32_t wdsel;
    uint32_t reset_done;
    uint32_t RSVD_0[1021];
    uint32_t reset_xor;
    uint32_t wdsel_xor;
    uint32_t reset_done_xor;
    uint32_t RSVDxor_0[1021];
    uint32_t reset_set;
    uint32_t wdsel_set;
    uint32_t reset_done_set;
    uint32_t RSVDset_0[1021];
    uint32_t reset_clr;
    uint32_t wdsel_clr;
    uint32_t reset_done_clr;
    uint32_t RSVDclr_0[1021];
} reset_ctrl_regs;

#define resets (*(volatile reset_ctrl_regs *)(_u(0x40020000)))

#define RESETS_RESET            (*(volatile uint32_t *)(0x40020000))
#define RESETS_WDSEL            (*(volatile uint32_t *)(0x40020004))
#define RESETS_RESET_DONE       (*(volatile uint32_t *)(0x40020008))
#define RESETS_RESET_XOR        (*(volatile uint32_t *)(0x40021000))
#define RESETS_WDSEL_XOR        (*(volatile uint32_t *)(0x40021004))
#define RESETS_RESET_DONE_XOR   (*(volatile uint32_t *)(0x40021008))
#define RESETS_RESET_SET        (*(volatile uint32_t *)(0x40022000))
#define RESETS_WDSEL_SET        (*(volatile uint32_t *)(0x40022004))
#define RESETS_RESET_DONE_SET   (*(volatile uint32_t *)(0x40022008))
#define RESETS_RESET_CLEAR      (*(volatile uint32_t *)(0x40023000))
#define RESETS_WDSEL_CLEAR      (*(volatile uint32_t *)(0x40023004))
#define RESETS_RESET_DONE_CLEAR (*(volatile uint32_t *)(0x40023008))

#define RESETS_RESET_UART1(v)       ((_u(v) & 0x1) << _u(27))
#define RESETS_RESET_UART1_MASK     RESETS_RESET_UART1(ALL1)

#define RESETS_RESET_UART0(v)       ((_u(v) & 0x1) << _u(26))
#define RESETS_RESET_UART0_MASK     RESETS_RESET_UART0(ALL1)

#define RESETS_RESET_PLL_SYS(v)     ((_u(v) & 0x1) << _u(14))
#define RESETS_RESET_PLL_SYS_MASK   RESETS_RESET_PLL_SYS(ALL1)

#define RESETS_RESET_IO_BANK0(v)    ((_u(v) & 0x1) << _u(6))
#define RESETS_RESET_IO_BANK0_MASK  RESETS_RESET_IO_BANK0(ALL1)

#endif
