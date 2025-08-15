#ifndef CSR_H
#define CSR_H

#define CSR_READ(csr_id)                     \
    ({                                        \
        uint32_t val;                        \
        __asm__ volatile (                   \
            "csrr %0, " #csr_id              \
            : "=r" (val));                   \
        val;                                 \
    })

#define CSR_WRITE(csr_id, val) \
    __asm__ volatile("csrw " #csr_id ", %0" :: "r"(val))

void csr_init(void);

#endif
