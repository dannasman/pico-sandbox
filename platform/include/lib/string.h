#ifndef STRING_H
#define STRING_H

#include <stdint.h>

int32_t strlen(const char *);
int32_t strcmp(const char *, const char *);

static inline char* u32_to_str(uint32_t n, char *s)
{
    s += 11;
    *--s = 0;
    do {
        char ost = n % 10;
        n /= 10;
        *--s = ost + '0';
    } while(n > 0);
    return s;
}


static inline char* u64_to_str(uint32_t n, char *s)
{
    s += 21;
    *--s = 0;
    do {
        char ost = n % 10;
        n /= 10;
        *--s = ost + '0';
    } while(n > 0);
    return s;
}

#endif
