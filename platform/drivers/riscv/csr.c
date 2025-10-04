#include "riscv/csr.h"

void csr_init(void)
{
    CSR_WRITE(0x320, 0);
}
