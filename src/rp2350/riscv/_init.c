#include <rp2350/resets.h>
#include <stdint.h>

extern void __stack_top();
extern void RESET_Handler();

static const uint32_t __attribute__((used, section(".embedded_block"))) __embedded_block[8] =
{
    0xffffded3,
    0x11010142,
    0x00000344,
    (uint32_t)(&RESET_Handler),
    (uint32_t)(&__stack_top),
    0x000004ff,
    0x00000000,
    0xab123579,
};

// TODO: figure out why DEFAULT_Handler can not be used...

void __attribute__ ((interrupt ("machine"), section(".data"))) default_handler(void);

void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_EXCEPTION_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_SSI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_MSI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_STI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_MTI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_SEI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) MTVEC_MEI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER0_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER0_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER0_IRQ_2_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER0_IRQ_3_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER1_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER1_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER1_IRQ_2_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TIMER1_IRQ_3_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PWM_IRQ_WRAP_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PWM_IRQ_WRAP_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) DMA_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) DMA_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) DMA_IRQ_2_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) DMA_IRQ_3_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) USBCTRL_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO0_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO0_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO1_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO1_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO2_IRQ_0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PIO2_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) IO_IRQ_BANK0_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) IO_IRQ_BANK0_NS_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) IO_IRQ_QSPI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) IO_IRQ_QSPI_NS_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SIO_IRQ_FIFO_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SIO_IRQ_BELL_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SIO_IRQ_FIFO_NS_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SIO_IRQ_BELL_NS_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SIO_IRQ_MTIMECMP_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) CLOCKS_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPI0_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPI1_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) UART0_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) UART1_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) ADC_IRQ_FIFO_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) I2C0_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) I2C1_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) OTP_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) TRNG_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PROC0_IRQ_CTI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PROC1_IRQ_CTI_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PLL_SYS_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) PLL_USB_IRQ_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPAREIRQ_IRQ_1_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPAREIRQ_IRQ_2_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPAREIRQ_IRQ_3_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPAREIRQ_IRQ_4_Handler(void);
void __attribute__ ((interrupt ("machine"), weak, alias("default_handler"), section(".data"))) SPAREIRQ_IRQ_5_Handler(void);

void __attribute__ ((naked, section(".data"), aligned(16)))  __vector_table(void)
{
    __asm__ volatile (
            ".org   __vector_table + 0*4;"
            "jal    zero, MTVEC_EXCEPTION_Handler;"
            ".org   __vector_table + 1*4;"
            "jal    zero, MTVEC_SSI_Handler;"
            ".org   __vector_table + 3*4;"
            "jal    zero, MTVEC_MSI_Handler;"
            ".org   __vector_table + 5*4;"
            "jal    zero, MTVEC_STI_Handler;"
            ".org   __vector_table + 7*4;"
            "jal    zero, MTVEC_MTI_Handler;"
            ".org   __vector_table + 9*4;"
            "jal    zero, MTVEC_SEI_Handler;"
            ".org   __vector_table + 11*4;"
            "jal    zero, MTVEC_MEI_Handler;"
            ".org   __vector_table + 16*4;"
            "jal    zero, TIMER0_IRQ_0_Handler;"
            "jal    zero, TIMER0_IRQ_1_Handler;"
            "jal    zero, TIMER0_IRQ_2_Handler;"
            "jal    zero, TIMER0_IRQ_3_Handler;"
            "jal    zero, TIMER1_IRQ_0_Handler;"
            "jal    zero, TIMER1_IRQ_1_Handler;"
            "jal    zero, TIMER1_IRQ_2_Handler;"
            "jal    zero, TIMER1_IRQ_3_Handler;"
            "jal    zero, PWM_IRQ_WRAP_0_Handler;"
            "jal    zero, PWM_IRQ_WRAP_1_Handler;"
            "jal    zero, DMA_IRQ_0_Handler;"
            "jal    zero, DMA_IRQ_1_Handler;"
            "jal    zero, DMA_IRQ_2_Handler;"
            "jal    zero, DMA_IRQ_3_Handler;"
            "jal    zero, USBCTRL_IRQ_Handler;"
            "jal    zero, PIO0_IRQ_0_Handler;"
            "jal    zero, PIO0_IRQ_1_Handler;"
            "jal    zero, PIO1_IRQ_0_Handler;"
            "jal    zero, PIO1_IRQ_1_Handler;"
            "jal    zero, PIO2_IRQ_0_Handler;"
            "jal    zero, PIO2_IRQ_1_Handler;"
            "jal    zero, IO_IRQ_BANK0_Handler;"
            "jal    zero, IO_IRQ_BANK0_NS_Handler;"
            "jal    zero, IO_IRQ_QSPI_Handler;"
            "jal    zero, IO_IRQ_QSPI_NS_Handler;"
            "jal    zero, SIO_IRQ_FIFO_Handler;"
            "jal    zero, SIO_IRQ_BELL_Handler;"
            "jal    zero, SIO_IRQ_FIFO_NS_Handler;"
            "jal    zero, SIO_IRQ_BELL_NS_Handler;"
            "jal    zero, SIO_IRQ_MTIMECMP_Handler;"
            "jal    zero, CLOCKS_IRQ_Handler;"
            "jal    zero, SPI0_IRQ_Handler;"
            "jal    zero, SPI1_IRQ_Handler;"
            "jal    zero, UART0_IRQ_Handler;"
            "jal    zero, UART1_IRQ_Handler;"
            "jal    zero, ADC_IRQ_FIFO_Handler;"
            "jal    zero, I2C0_IRQ_Handler;"
            "jal    zero, I2C1_IRQ_Handler;"
            "jal    zero, OTP_IRQ_Handler;"
            "jal    zero, TRNG_IRQ_Handler;"
            "jal    zero, PROC0_IRQ_CTI_Handler;"
            "jal    zero, PROC1_IRQ_CTI_Handler;"
            "jal    zero, PLL_SYS_IRQ_Handler;"
            "jal    zero, PLL_USB_IRQ_Handler;"
            "jal    zero, SPAREIRQ_IRQ_1_Handler;"
            "jal    zero, SPAREIRQ_IRQ_2_Handler;"
            "jal    zero, SPAREIRQ_IRQ_3_Handler;"
            "jal    zero, SPAREIRQ_IRQ_4_Handler;"
            "jal    zero, SPAREIRQ_IRQ_5_Handler;"
            : /* no output */
            : /* immediate input */
            : /* no clobbers */);
};


void default_handler(void)
{
    resets.reset = 0x1ffffff;
    __asm__ volatile ("csrrc x0, mstatus, %0" :: "r"(0x8));
    while(1)
        __asm__ volatile ("wfi");
}
