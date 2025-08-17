#ifndef LOG_UTILS_H
#define LOG_UTILS_H

#include <time.h>
#include <pl011.h>
#include <util/string.h>

static inline void log(const char * msg) {
    uint64_t time64;
    uint32_t time;
    char s[21];
    
    time64 = current_us();
    time = (uint32_t)(time64 & 0xFFFFFFFFUL);
    uart_putc('[');
    uart_puts(u32_to_str(time, s));
    uart_puts("]: ");
    uart_puts(msg);
    uart_putc('\n');
}

#endif
