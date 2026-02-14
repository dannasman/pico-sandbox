#include <stddef.h>
#include <stdbool.h>
#include <fs.h>
#include <gpio.h>
#include <led.h>
#include <log.h>
#include <pl011.h>
#include <time.h>
#include <cpu.h>
#include <shell.h>

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
    fs_init();
    shell_init();

    log("Sandbox initialized!");
    led_on();

    shell_run();
#if 0
    for(;;) {
        byte = uart_getc();
        uart_putc(byte);
    }
#endif
}
