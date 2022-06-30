#include "sw_uart.h"

due_sw_uart uart;

void setup() {
  Serial.begin(9600);
  sw_uart_setup(&uart, 4, 1, 8); //SW_UART_EVEN_PARITY);
}

void loop() {
 delay(2000);
 transmite_byte();
}

void transmite_byte() {
  char data = 'C';
  Serial.println("Enviando caracter C");
 
  // Enviar msg
  sw_uart_transmite(&uart, data); 

}
