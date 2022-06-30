#ifndef SW_UART_HEADER
#define SW_UART_HEADER

#include <Arduino.h>

struct due_sw_uart {
	int pin_tx;
	int baudrate;
	int stopbits;
	int paritybit;
  int databits;
};

typedef struct due_sw_uart due_sw_uart;

void sw_uart_setup(due_sw_uart *uart, int tx,  int stopbits, int databits); //, int paritybit);
void  sw_uart_transmite(due_sw_uart *uart, char data);

void _sw_uart_wait_half_T(due_sw_uart *uart);
void _sw_uart_wait_T(due_sw_uart *uart);

#endif
