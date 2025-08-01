#ifndef TIME_H
#define TIME_H

#define CYCLE_COUNT 12  

void tick_generator_init(void);
uint64_t current_us(void);
void delay_us(uint32_t);

#endif
