#include <stddef.h>
#include <stdbool.h>
#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <time.h>
#include <utils/cpu.h>
#include <utils/log.h>

#if defined(CONFIG_MACH_RISCV)
#include <riscv/csr.h>
#include <riscv/irq.h>
#else
#include <arm/dwt.h>
#include <arm/irq.h>
#endif

void main(void) {
    uint8_t byte;
    tick_generator_init();
#if defined(CONFIG_MACH_RISCV)
    csr_init();
    irq_init();
#else
    dwt_init();
#endif
    gpio_init();
    led_init();
    uart_init();

    //uart_flush();

    led_on();
    uart_puts("Sandbox initialized!\n");

    for(;;) {
        byte = uart_getc();
        uart_putc(byte);
    }
}
