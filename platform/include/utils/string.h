#ifndef STRING_UTILS_H
#define STRING_UTILS_H

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

#endif
