#include <rp2350/io_bank0.h>
#include <rp2350/pads_bank0.h>
#include <rp2350/resets.h>
#include <rp2350/uart.h>

#include "pl011.h"

void uart_init() {
    resets.reset_clr = RESETS_RESET_UART0_MASK;
    while ((resets.reset_done & RESETS_RESET_UART0_MASK) != RESETS_RESET_UART0_MASK) {}

    pads_bank0.gpio0_set = PADS_BANK0_GPIO0_IE_MASK;
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_OD_MASK;
    io_bank0.gpio0_ctrl = IO_BANK0_GPIO0_CTRL_FUNCSEL(UART0_TX);
    pads_bank0.gpio0_clr = PADS_BANK0_GPIO0_ISO_MASK;

    pads_bank0.gpio1_set = PADS_BANK0_GPIO1_IE_MASK;
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_OD_MASK;
    io_bank0.gpio1_ctrl = IO_BANK0_GPIO1_CTRL_FUNCSEL(UART0_RX);
    pads_bank0.gpio1_clr = PADS_BANK0_GPIO1_ISO_MASK;
}


