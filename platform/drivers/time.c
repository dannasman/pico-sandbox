#include <rp2350/ticks.h>
#include <rp2350/timer.h>
#include <utils/cpu.h>

#include "time.h"

void tick_generator_init(void)
{
    ticks.timer0_ctrl_clr = TICKS_TIMER0_CTRL_ENABLE_MASK;
    while ((ticks.timer0_ctrl & TICKS_TIMER0_CTRL_RUNNING_MASK) == TICKS_TIMER0_CTRL_RUNNING_MASK) {}

    ticks.timer0_cycles = CYCLE_COUNT;
    ticks.timer0_ctrl_set = TICKS_TIMER0_CTRL_ENABLE_MASK;
    while (!(ticks.timer0_ctrl & TICKS_TIMER0_CTRL_RUNNING_MASK)) {}
}

uint64_t current_us(void)
{
    uint64_t ret;
    uint32_t hi = timer0.timerawh;
    uint32_t lo;
    do {
        lo = timer0.timerawl;
        uint32_t next_hi = timer0.timerawh;
        if (hi == next_hi) break;
        hi = next_hi;
    } while (1);
    ret = ((uint64_t) hi << 32u) | lo;
    ret *= CYCLE_COUNT;
    return ret;
}

void delay_us(uint64_t delay) {
    uint64_t start = current_us();
    while (current_us() - start < delay)
        tight_loop_contents();
}
