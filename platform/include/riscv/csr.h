#ifndef CSR_H
#define CSR_H

#include <stdint.h>

#define CSR_READ(csr_id, ret)   __asm__ volatile ("csrr %0, " #csr_id: "=r" (ret))
#define CSR_WRITE(csr_id, val)  __asm__ volatile("csrw " #csr_id ", %0" :: "r"(val))
#define CSR_SET(csr_id, val)    __asm__ volatile("csrs " #csr_id ", %0" :: "r"(val))

static inline void csr_set_bits_mstatus(uint32_t mask) {
    __asm__ volatile ("csrrs    zero, mstatus, %0"
                      : /* output: none */
                      : "r" (mask)  /* input : register */
                      : /* clobbers: none */);
}

static inline void csr_clr_bits_mstatus(uint32_t mask) {
    __asm__ volatile ("csrrc    zero, mstatus, %0"
                      : /* output: none */
                      : "r" (mask) /* input : from register */
                      : /* clobbers: none */);
}

static inline uint32_t csr_read_mstatus(void) {
    uint32_t value;
    __asm__ volatile ("csrr    %0, mstatus"
                      : "=r" (value)  /* output : register */
                      : /* input : none */
                      : /* clobbers: none */);
    return value;
}

static inline void csr_write_mstatus(uint32_t value) {
    __asm__ volatile ("csrw    mstatus, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_write_mtvec(uint32_t value) {
    __asm__ volatile ("csrw    mtvec, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_write_mie(uint32_t value) {
    __asm__ volatile ("csrw    mie, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_set_bits_mie(uint32_t mask) {
    __asm__ volatile ("csrrs    zero, mie, %0"
                      : /* output: none */
                      : "r" (mask)  /* input : register */
                      : /* clobbers: none */);
}

static inline void csr_write_mip(uint32_t value) {
    __asm__ volatile ("csrw    mip, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_set_bits_mip(uint32_t mask) {
    __asm__ volatile ("csrrs    zero, mip, %0"
                      : /* output: none */
                      : "r" (mask)  /* input : register */
                      : /* clobbers: none */);
}

static inline uint32_t csr_read_meiea(void) {
    uint32_t value;
    __asm__ volatile ("csrr    %0, meiea"
                      : "=r" (value)  /* output : register */
                      : /* input : none */
                      : /* clobbers: none */);
    return value;
}

static inline void csr_write_meiea(uint32_t value) {
    __asm__ volatile ("csrw    0xbe0, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_write_meifa(uint32_t value) {
    __asm__ volatile ("csrw    0xbe2, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline uint32_t csr_read_meinext(void) {
    uint32_t value;
    __asm__ volatile ("csrr    %0, 0xbe4"
                      : "=r" (value)  /* output : register */
                      : /* input : none */
                      : /* clobbers: none */);
    return value;
}

static inline void csr_write_meinext(uint32_t value) {
    __asm__ volatile ("csrw    0xbe4, %0"
                      : /* output: none */
                      : "r" (value) /* input : from register */
                      : /* clobbers: none */);
}

static inline void csr_set_bits_meinext(uint32_t mask) {
    __asm__ volatile ("csrrs    zero, 0xbe4, %0"
                      : /* output: none */
                      : "r" (mask)  /* input : register */
                      : /* clobbers: none */);
}

void csr_init(void);

#endif
