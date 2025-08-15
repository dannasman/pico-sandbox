#include <stddef.h>
#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <time.h>
#include <util/cpu.h>
#include <util/string.h>

#if defined(CONFIG_MACH_RISCV)
#include <csr.h>
#else
#include <dwt.h>
#endif

void main(void) {
    tick_generator_init();
#if defined(CONFIG_MACH_RISCV)
    csr_init();
#else
    dwt_init();
#endif
    uint32_t start = cycle_count();
    gpio_init();
    led_init();
    uart_init();
    uint32_t time = cycle_count() - start;

    led_on();

    uart_flush();
    char s[11];
    uart_puts(u32_to_str((uint32_t)(time & 0xFFFFFFFFUL), s));
    uart_putc('\n');

    for(;;) {
        uint8_t c = uart_getc();
        uart_putc(c);
    }
}
