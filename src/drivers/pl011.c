#include <stddef.h>
#include <stdint.h>
#include <rp2350/clocks.h>
#include <rp2350/io_bank0.h>
#include <rp2350/pads_bank0.h>
#include <rp2350/pll.h>
#include <rp2350/resets.h>
#include <rp2350/uart.h>

#include <time.h>
#include <util/cpu.h>

#include "pl011.h"

void uart_init(void)
{
    // initialize GPIO
    pads_bank0.gpio0_set = PADS_BANK0_GPIO0_IE_MASK;
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_OD_MASK;
    io_bank0.gpio0_ctrl = IO_BANK0_GPIO0_CTRL_FUNCSEL(UART0_TX);
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_ISO_MASK;

    pads_bank0.gpio1_set = PADS_BANK0_GPIO1_IE_MASK;
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_OD_MASK;
    io_bank0.gpio1_ctrl = IO_BANK0_GPIO1_CTRL_FUNCSEL(UART0_RX);
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_ISO_MASK;

    resets.reset_clr = RESETS_RESET_UART0_MASK;
    while ((resets.reset_done & RESETS_RESET_UART0_MASK) != RESETS_RESET_UART0_MASK) {}

    //uart0.uarticr = 0x7ff;

    uart0.uartibrd = UART_UARTIBRD_BAUD_DIVINT(26);
    uart0.uartfbrd = UART_UARTFBRD_BAUD_DIVFRAC(3);

    uart0.uartlcr_h = UART_UARTLCR_H_WLEN(3) | UART_UARTLCR_H_FEN_MASK;

    uart0.uartcr = UART_UARTCR_RXE_MASK | UART_UARTCR_TXE_MASK | UART_UARTCR_UARTEN_MASK;

    delay(150);
}

void uart_flush(void)
{
    while ((uart0.uartfr & UART_UARTFR_BUSY_MASK) == UART_UARTFR_BUSY_MASK)
        tight_loop_contents();
}

static inline void uart_putc_raw(uint8_t c)
{
    while ((uart0.uartfr & UART_UARTFR_TXFF_MASK) == UART_UARTFR_TXFF_MASK)
        tight_loop_contents();
    uart0.uartdr = c;
    while ((uart0.uartfr & UART_UARTFR_BUSY_MASK) == UART_UARTFR_BUSY_MASK)
        tight_loop_contents();
}

void uart_putc(uint8_t c)
{
    uart_putc_raw(c);
    if (c == '\n')
        uart_putc_raw('\r');
}

void uart_puts(const char *s) {
    while (*s)
        uart_putc((uint8_t)(*s++));
}

uint8_t uart_getc(void)
{
    uint8_t c;
    while ((uart0.uartfr & UART_UARTFR_RXFE_MASK) == UART_UARTFR_RXFE_MASK) {}
    c = (uint8_t)uart0.uartdr;
    return c;
}

