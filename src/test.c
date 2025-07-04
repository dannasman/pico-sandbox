#include <gpio.h>
#include <led.h>
#include <pl011.h>

#define DELAY 0x00400000

int main(void) {
    gpio_init();
    led_init();
    uart_init();
#ifdef CONFIG_MACH_RISCV
    led_on();
#endif
    while (1) {
        led_toggle();
        for (volatile uint32_t i=0; i<DELAY; i++)
            continue;
    }
}
