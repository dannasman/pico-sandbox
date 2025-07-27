#include <gpio.h>
#include <led.h>
#include <pl011.h>

#define DELAY 0x00400000

int main(void) {
    gpio_init();
    led_init();
    uart_init();
#if defined(CONFIG_MACH_RISCV)
    for (uint32_t i=0; i<3*DELAY; i++)
        continue;
#endif
    led_on();
    for(;;) {
        uint8_t c = uart_getc();
        uart_putc(c);
    }
}
