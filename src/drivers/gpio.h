#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>

void register_gpio_irq_callback(void (*)());
uint8_t get_irq_status_for_pin(uint8_t);

#endif
