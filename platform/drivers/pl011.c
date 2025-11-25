#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <rp2350/clocks.h>
#include <rp2350/io_bank0.h>
#include <rp2350/pads_bank0.h>
#include <rp2350/pll.h>
#include <rp2350/resets.h>
#include <rp2350/uart.h>

#ifdef CONFIG_MACH_RISCV
#include <riscv/irq.h>
#define UART0_IRQ_NO    33U
#define UART0_IRQ_PRI   1U
#define UART1_IRQ_NO    34U
#define UART1_IRQ_PRI   1U
#else
#include <arm/irq.h>
#define UART0_IRQ_NO    33U
#define UART0_IRQ_PRI   1U
#define UART1_IRQ_NO    34U
#define UART1_IRQ_PRI   1U
#endif

#include <time.h>
#include <utils/cpu.h>

#include "pl011.h"
#include "led.h"

#define UART_BUFSIZE    256

static volatile uint16_t rx_head = 0;
static volatile uint16_t rx_tail = 0;
static uint8_t rx_buf[UART_BUFSIZE];
static inline bool rx_buf_empty(void) {
    return (rx_head == rx_tail);
}
static inline bool rx_buf_full(void) {
    return ((rx_head + 1) % UART_BUFSIZE) == rx_tail;
}

static volatile uint16_t tx_head = 0;
static volatile uint16_t tx_tail = 0;
static uint8_t tx_buf[UART_BUFSIZE];
static inline bool tx_buf_empty(void) {
    return (tx_head == tx_tail);
}
static inline bool tx_buf_full(void) {
    return ((tx_head + 1) % UART_BUFSIZE) == tx_tail;
}

void uart_init(void)
{
    // initialize GPIO
    pads_bank0.gpio0_set = PADS_BANK0_GPIO0_IE_MASK;
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_OD_MASK;
    io_bank0.gpio0_ctrl = IO_BANK0_GPIO0_CTRL_FUNCSEL(UART0_TX);
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_ISO_MASK;

    pads_bank0.gpio1_set = PADS_BANK0_GPIO1_IE_MASK;
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_OD_MASK | PADS_BANK0_GPIO1_PDE_MASK;
    io_bank0.gpio1_ctrl = IO_BANK0_GPIO1_CTRL_FUNCSEL(UART0_RX);
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_ISO_MASK;

    resets.reset_clr = RESETS_RESET_UART0_MASK;
    while ((resets.reset_done & RESETS_RESET_UART0_MASK) != RESETS_RESET_UART0_MASK) {}

    uart0.uartifls = UART_UARTIFLS_RXIFLSEL(0x0) | UART_UARTIFLS_TXIFLSEL(0x4);

    uart0.uarticr = 0x7ff;
    uart0.uartimsc_set = UART_UARTIMSC_RXIM_MASK | UART_UARTIMSC_RTIM_MASK;

    uart0.uartibrd = UART_UARTIBRD_BAUD_DIVINT(26);
    uart0.uartfbrd = UART_UARTFBRD_BAUD_DIVFRAC(3);

    uart0.uartlcr_h = UART_UARTLCR_H_WLEN(3) | UART_UARTLCR_H_FEN_MASK;

    uart0.uartcr = UART_UARTCR_RXE_MASK | UART_UARTCR_TXE_MASK | UART_UARTCR_UARTEN_MASK;

    irq_enable(UART0_IRQ_NO, UART0_IRQ_PRI);
    //irq_enable(UART1_IRQ_NO, UART1_IRQ_PRI);
}

void uart_flush(void)
{
    uint32_t flush_mask = UART_UARTFR_BUSY_MASK | UART_UARTFR_TXFF_MASK;
    while (!tx_buf_empty())
        tight_loop_contents();

    while ((uart0.uartfr & flush_mask) != 0)
        tight_loop_contents();
}

static inline void uart_putc_raw(uint8_t c)
{
    while (tx_buf_full()) {
        tight_loop_contents();
    }

    tx_buf[tx_head] = c;
    tx_head = (tx_head + 1) % UART_BUFSIZE;

    if ((uart0.uartfr & UART_UARTFR_TXFF_MASK) == 0) {
        uart0.uartdr = tx_buf[tx_tail];
        tx_tail = (tx_tail + 1) % UART_BUFSIZE;
    }


    uart0.uartimsc_set = UART_UARTIMSC_TXIM_MASK;
}

void uart_putc(uint8_t c)
{
    if (c == '\n')
        uart_putc_raw('\r');
    uart_putc_raw(c);
}

void uart_puts(const char *s) {
    while (*s)
        uart_putc((uint8_t)(*s++));
}

uint8_t uart_getc(void)
{
    while (rx_buf_empty()) {
        tight_loop_contents();
    }

    uint8_t c = rx_buf[rx_tail];
    rx_tail = (rx_tail + 1) % UART_BUFSIZE;
    return c;
}

void UART0_IRQ_Handler(void)
{
    if (uart0.uartmis & UART_UARTMIS_TXMIS_MASK) {
        while (((uart0.uartfr & UART_UARTFR_TXFF_MASK) == 0) && !tx_buf_empty()) {
            uart0.uartdr = tx_buf[tx_tail];
            tx_tail = (tx_tail + 1) % UART_BUFSIZE;
        }

        if (tx_buf_empty()) {
            uart0.uartimsc_clr = UART_UARTIMSC_TXIM_MASK;
        }

        uart0.uarticr = UART_UARTICR_TXIC_MASK;
    }

    if (uart0.uartmis & (UART_UARTMIS_RXMIS_MASK | UART_UARTMIS_RTMIS_MASK)) {
        while ((uart0.uartfr & UART_UARTFR_RXFE_MASK) == 0) {
            uint8_t c = uart0.uartdr;
            uint16_t next = (rx_head + 1) % UART_BUFSIZE;
            rx_buf[rx_head] = c;
            rx_head = next;
        }
        uart0.uarticr = UART_UARTICR_RXIC_MASK | UART_UARTICR_RTIC_MASK;
    }
}
