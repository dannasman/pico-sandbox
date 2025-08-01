#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <time.h>
#include <utils.h>

#define DELAY 0x00400000

void main(void) {
    tick_generator_init();
    uint64_t start = current_us();
    gpio_init();
    led_init();
    uart_init();
    uint64_t end = current_us();

    led_on();

    uart_flush();
    const char *test = "Sandbox initialized!\n";
    uart_puts(test);

    for(;;) {
        uint8_t c = uart_getc();
        uart_putc(c);
    }
}
