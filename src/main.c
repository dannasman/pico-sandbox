#include <stddef.h>
#include <stdbool.h>
#include <fft.h>
#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <time.h>
#include <util/cpu.h>
#include <util/log.h>

#if defined(CONFIG_MACH_RISCV)
#include <csr.h>
#else
#include <dwt.h>
#endif

void measure_fft(void)
{
    uint8_t byte;
    uint32_t size;
    uint32_t cycles;
    complex_t input[1024];

    // notify host: ready to take input
    for (uint32_t i = 0; i < 3; i++)
        uart_putc(0x3);

    size = 0U;
    byte = uart_getc();
    size |= byte;
    byte = uart_getc();
    size |= (byte << 8);
    byte = uart_getc();
    size |= (byte << 16);
    byte = uart_getc();
    size |= (byte << 24);

    uart_putc('O');
    uart_putc('K');

    if (size > 1024)
        size = 1024;

    for (uint32_t i = 0; i < size; i++) {
        int32_t r = uart_getc();
        input[i].r = (r-128) << 24;
        input[i].i = 0;
    }

    //log("Payload received");
    // notify host: ready to send output
    for (uint32_t i = 0; i < 3; i++)
        uart_putc(0x3);

    char s[11];
    uart_puts(u32_to_str(1, s));
    uart_putc('\n');
    for (uint32_t i = 0; i < 1; i++) {
        cycles = cycle_count();
        fft(input, size, false);
        cycles = cycle_count() - cycles;
        uart_puts(u32_to_str(cycles, s));
        uart_putc('\n');
    }
    
    uart_puts(u32_to_str(size, s));
    uart_putc('\n');
    for (uint32_t k = 0; k < size; k++) {
        int64_t rr = (int64_t)input[k].r*input[k].r;
        int64_t ii = (int64_t)input[k].i*input[k].i;
        int64_t mag = rr+ii;
        mag += (mag >= 0) ? (1LL << 30) : -(1LL << 30);
        mag >>= 31;

        uart_puts(u32_to_str((uint32_t)mag, s));
        uart_putc('\n');
    }
}

void main(void) {
    uint8_t byte;
    tick_generator_init();
#if defined(CONFIG_MACH_RISCV)
    csr_init();
#else
    dwt_init();
#endif
    gpio_init();
    led_init();
    uart_init();
    uart_flush();
    led_on();
    //log("Sandbox initialized");

    measure_fft();

    for(;;) {
        tight_loop_contents();
    }
}
