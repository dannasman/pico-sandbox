#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdint.h>

typedef struct {
    int32_t r;
    int32_t i;
} complex_t;


static inline complex_t cadd(complex_t a, complex_t b)
{
    int64_t r = (int64_t)a.r+b.r;
    if (r > INT32_MAX) r = INT32_MAX;
    if (r < INT32_MIN) r = INT32_MIN;
    int64_t i = (int64_t)a.i+b.i;
    if (i > INT32_MAX) i = INT32_MAX;
    if (i < INT32_MIN) i = INT32_MIN;
    complex_t res;
    res.r = r;
    res.i = i;
    return res;
}

static inline complex_t csub(complex_t a, complex_t b)
{
    int64_t r = (int64_t)a.r-b.r;
    if (r > INT32_MAX) r = INT32_MAX;
    if (r < INT32_MIN) r = INT32_MIN;
    int64_t i = (int64_t)a.i-b.i;
    if (i > INT32_MAX) i = INT32_MAX;
    if (i < INT32_MIN) i = INT32_MIN;
    complex_t res;
    res.r = r;
    res.i = i;
    return res;
}

static inline complex_t cmul(complex_t a, complex_t b)
{

    int64_t r = (int64_t)a.r*b.r - (int64_t)a.i*b.i;
    int64_t i = (int64_t)a.r*b.i + (int64_t)a.i*b.r;

    r += (r >= 0) ? (1LL << 30) : -(1LL << 30);
    i += (i >= 0) ? (1LL << 30) : -(1LL << 30);

    complex_t res;
    res.r = (int32_t)(r >> 31);
    res.i = (int32_t)(i >> 31);

    return res;
}

#endif
