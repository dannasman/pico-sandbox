#include <rp2350/resets.h>
#include <stdint.h>

extern void __stack_top();
extern void RESET_Handler();

// TODO: figure out why DEFAULT_Handler can not be used...
void default_handler()
{
    resets.reset = 0x1ffffff;
    __asm__("CPSID i");
    while(1)
        __asm__("wfi");
}

void __attribute__ ((weak, alias("default_handler"))) NMI_Handler();
void __attribute__ ((weak, alias("default_handler"))) HARDFAULT_Handler();
void __attribute__ ((weak, alias("default_handler"))) MEMMANAGE_Handler();
void __attribute__ ((weak, alias("default_handler"))) BUSFAULT_Handler();
void __attribute__ ((weak, alias("default_handler"))) USAGEFAULT_Handler();
void __attribute__ ((weak, alias("default_handler"))) SECUREFAULT_Handler();
void __attribute__ ((weak, alias("default_handler"))) SVC_Handler();
void __attribute__ ((weak, alias("default_handler"))) DEBUGMON_Handler();
void __attribute__ ((weak, alias("default_handler"))) PENDSV_Handler();
void __attribute__ ((weak, alias("default_handler"))) SYSTICK_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER0_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER0_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER0_IRQ_2_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER0_IRQ_3_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER1_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER1_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER1_IRQ_2_Handler();
void __attribute__ ((weak, alias("default_handler"))) TIMER1_IRQ_3_Handler();
void __attribute__ ((weak, alias("default_handler"))) PWM_IRQ_WRAP_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) PWM_IRQ_WRAP_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) DMA_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) DMA_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) DMA_IRQ_2_Handler();
void __attribute__ ((weak, alias("default_handler"))) DMA_IRQ_3_Handler();
void __attribute__ ((weak, alias("default_handler"))) USBCTRL_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO0_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO0_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO1_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO1_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO2_IRQ_0_Handler();
void __attribute__ ((weak, alias("default_handler"))) PIO2_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) IO_IRQ_BANK0_Handler();
void __attribute__ ((weak, alias("default_handler"))) IO_IRQ_BANK0_NS_Handler();
void __attribute__ ((weak, alias("default_handler"))) IO_IRQ_QSPI_Handler();
void __attribute__ ((weak, alias("default_handler"))) IO_IRQ_QSPI_NS_Handler();
void __attribute__ ((weak, alias("default_handler"))) SIO_IRQ_FIFO_Handler();
void __attribute__ ((weak, alias("default_handler"))) SIO_IRQ_BELL_Handler();
void __attribute__ ((weak, alias("default_handler"))) SIO_IRQ_FIFO_NS_Handler();
void __attribute__ ((weak, alias("default_handler"))) SIO_IRQ_BELL_NS_Handler();
void __attribute__ ((weak, alias("default_handler"))) SIO_IRQ_MTIMECMP_Handler();
void __attribute__ ((weak, alias("default_handler"))) CLOCKS_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPI0_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPI1_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) UART0_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) UART1_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) ADC_IRQ_FIFO_Handler();
void __attribute__ ((weak, alias("default_handler"))) I2C0_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) I2C1_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) OTP_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) TRNG_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) PROC0_IRQ_CTI_Handler();
void __attribute__ ((weak, alias("default_handler"))) PROC1_IRQ_CTI_Handler();
void __attribute__ ((weak, alias("default_handler"))) PLL_SYS_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) PLL_USB_IRQ_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPAREIRQ_IRQ_1_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPAREIRQ_IRQ_2_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPAREIRQ_IRQ_3_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPAREIRQ_IRQ_4_Handler();
void __attribute__ ((weak, alias("default_handler"))) SPAREIRQ_IRQ_5_Handler();
#define RESERVED ((void(*)())0xdeadbeef)
void (* const __vector_table[])(void)  __attribute__((section(".vectors"))) =
{
    &__stack_top,
    RESET_Handler,
    NMI_Handler,
    HARDFAULT_Handler,
    RESERVED,
    RESERVED,
    RESERVED,
    RESERVED,
    RESERVED,
    RESERVED,
    RESERVED,
    SVC_Handler,
    RESERVED,
    RESERVED,
    PENDSV_Handler,
    SYSTICK_Handler,
    TIMER0_IRQ_0_Handler,
    TIMER0_IRQ_1_Handler,
    TIMER0_IRQ_2_Handler,
    TIMER0_IRQ_3_Handler,
    TIMER1_IRQ_0_Handler,
    TIMER1_IRQ_1_Handler,
    TIMER1_IRQ_2_Handler,
    TIMER1_IRQ_3_Handler,
    PWM_IRQ_WRAP_0_Handler,
    PWM_IRQ_WRAP_1_Handler,
    DMA_IRQ_0_Handler,
    DMA_IRQ_1_Handler,
    DMA_IRQ_2_Handler,
    DMA_IRQ_3_Handler,
    USBCTRL_IRQ_Handler,
    PIO0_IRQ_0_Handler,
    PIO0_IRQ_1_Handler,
    PIO1_IRQ_0_Handler,
    PIO1_IRQ_1_Handler,
    PIO2_IRQ_0_Handler,
    PIO2_IRQ_1_Handler,
    IO_IRQ_BANK0_Handler,
    IO_IRQ_BANK0_NS_Handler,
    IO_IRQ_QSPI_Handler,
    IO_IRQ_QSPI_NS_Handler,
    SIO_IRQ_FIFO_Handler,
    SIO_IRQ_BELL_Handler,
    SIO_IRQ_FIFO_NS_Handler,
    SIO_IRQ_BELL_NS_Handler,
    SIO_IRQ_MTIMECMP_Handler,
    CLOCKS_IRQ_Handler,
    SPI0_IRQ_Handler,
    SPI1_IRQ_Handler,
    UART0_IRQ_Handler,
    UART1_IRQ_Handler,
    ADC_IRQ_FIFO_Handler,
    I2C0_IRQ_Handler,
    I2C1_IRQ_Handler,
    OTP_IRQ_Handler,
    TRNG_IRQ_Handler,
    PROC0_IRQ_CTI_Handler,
    PROC1_IRQ_CTI_Handler,
    PLL_SYS_IRQ_Handler,
    PLL_USB_IRQ_Handler,
    SPAREIRQ_IRQ_1_Handler,
    SPAREIRQ_IRQ_2_Handler,
    SPAREIRQ_IRQ_3_Handler,
    SPAREIRQ_IRQ_4_Handler,
    SPAREIRQ_IRQ_5_Handler,
};

static const uint32_t __attribute__((used, section(".embedded_block"))) __embedded_block[5] =
{
    0xffffded3,
    0x10210142,
    0x000001ff,
    0x00000000,
    0xab123579,
};

void __attribute__((used, section(".init" ))) _entry_point()
{
    RESET_Handler();
}
