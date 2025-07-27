#include <gpio.h>
#include <led.h>
#include <pl011.h>
#include <utils.h>

#define DELAY 0x00400000

int main(void) {
    gpio_init();
    led_init();
    uart_init();

    delay(1);
    led_on();
    for(;;) {
        uint8_t c = uart_getc();
        uart_putc(c);
    }
}
