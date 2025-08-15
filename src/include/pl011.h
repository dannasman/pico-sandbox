#ifndef PL011_H
#define PL011_H

#define UART0_RX    0x2
#define UART0_TX    0x2

void uart_flush(void);
void uart_init(void);
void uart_putc(uint8_t);
void uart_puts(const char *);
uint8_t uart_getc(void);

#endif
