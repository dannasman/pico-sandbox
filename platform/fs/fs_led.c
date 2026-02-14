#include <led.h>
#include <lib/string.h>
#include <pl011.h>

#include "fs.h"

#define LED_DATA_SIZE   1

static void fs_led_read(char *buf, size_t n)
{
    if (n >= 2) {
        buf[0] = led_state() ? '1' : '0';
        buf[1] = '\0';
    }
}

static void fs_led_write(const char *data) {
    if (strlen(data) == 1) {
        if (data[0] == '0') {
            led_off();
        } else if (data[0] == '1') {
            led_on();
        }
    }
}

static const struct fs_ops fs_led_ops = {
    .read = &fs_led_read,
    .write = &fs_led_write
};

void fs_led_init(void) {
    fs_add_dev("led", &fs_led_ops);
}
