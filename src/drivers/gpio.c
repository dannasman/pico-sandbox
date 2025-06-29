#include <rp2350/io_bank0.h>
#include <rp2350/resets.h>

#include "gpio.h"

static void(*callback[5])();
static uint8_t num_registered_callbacks;
static uint32_t gpio_irq_events[4];

/* Set up interrupts */
void register_gpio_irq_callback(void (*pf)())
{
    /*
     * No need for reset?
    resets.reset_clr = RESETS_RESET_IO_BANK0_MASK;
    while ((resets.reset_done & RESETS_RESET_IO_BANK0_MASK) != RESETS_RESET_IO_BANK0_MASK) {}
    */

    callback[num_registered_callbacks] = pf;
    num_registered_callbacks++;
}

uint8_t get_irq_status_for_pin(uint8_t pin)
{
    uint8_t events = ((uint8_t*) gpio_irq_events)[pin/2];
    if (pin/2 == 0)
        events &= 0xf;
    else
        events >>= 4;
    return events;
}

void __attribute__((interrupt, section(".data"))) IO_IRQ_BANK0_Handler()
{
    for (uint8_t i=0; i<4; i++)
        gpio_irq_events[i] = (&(io_bank0.proc0_ints0))[i];

    for (uint8_t i=0; i<num_registered_callbacks; i++)
        callback[i]();

    for (uint8_t i=0; i<4; i++)
        (&(io_bank0.intr0))[i] = gpio_irq_events[i];
}
