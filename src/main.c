#include <stddef.h>
#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <time.h>
#include <util/cpu.h>
#include <util/string.h>

void main(void) {
    tick_generator_init();
    uint64_t start = current_us();
    gpio_init();
    led_init();
    uart_init();
    uint64_t time = current_us() - start;

    led_on();

    uart_flush();
    char s[11];
    uart_puts(u32_to_str((uint32_t)(time & 0xFFFFFFFFUL), s));

    for(;;) {
        uint8_t c = uart_getc();
        uart_putc(c);
    }
}
