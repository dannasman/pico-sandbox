#include <rp2350/io_bank0.h>
#include <rp2350/pads_bank0.h>
#include <rp2350/resets.h>
#include <rp2350/sio.h>
#include "led.h"

#define PADS_BANK0_BITS (PADS_BANK0_GPIO25_OD(0) \
        | PADS_BANK0_GPIO25_IE(0) \
        | PADS_BANK0_GPIO25_DRIVE(0) \
        | PADS_BANK0_GPIO25_PUE(0) \
        | PADS_BANK0_GPIO25_PDE(0) \
        | PADS_BANK0_GPIO25_SCHMITT(0) \
        | PADS_BANK0_GPIO25_SLEWFAST(0))

#define IO_BANK0_BITS   (IO_BANK0_GPIO25_CTRL_IRQOVER(0) \
        | IO_BANK0_GPIO25_CTRL_INOVER(0) \
        | IO_BANK0_GPIO25_CTRL_OEOVER(0) \
        | IO_BANK0_GPIO25_CTRL_OUTOVER(0) \
        | IO_BANK0_GPIO25_CTRL_FUNCSEL(5))

/* gpio should be initialized before calling */
void led_init(void)
{
    pads_bank0.gpio25 = PADS_BANK0_BITS;
    io_bank0.gpio25_ctrl = IO_BANK0_BITS;
    sio.gpio_oe_set = (1 << 25);
}

void led_on(void)
{
    sio.gpio_out_set = (1 << 25);
}

void led_off(void)
{
    sio.gpio_out_clr = (1 << 25);
}

void led_toggle(void)
{
    sio.gpio_out_xor = (1 << 25);
}
