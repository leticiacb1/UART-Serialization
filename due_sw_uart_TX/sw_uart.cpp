#include "sw_uart.h"
#pragma GCC optimize ("-O3")

void sw_uart_setup(due_sw_uart *uart, int tx, int stopbits, int databits){ //, int paritybit) {
	
	uart->pin_tx     = tx;
	uart->stopbits   = stopbits;

  //Nãodefinido ainda! Não "seto esse valor no set up". Seto apenas após calcular o data que sera enviado.
	//uart->paritybit  = paritybit;   
  
  uart->databits   = databits;
  pinMode(tx, OUTPUT);

  // Inicalmente setado para valor alto 
  //(necessario pra identificação do start bit)
  digitalWrite(tx, HIGH);
  
}

int calc_even_parity(char data) {
  int ones = 0;

  for(int i = 0; i < 8; i++) {
    ones += (data >> i) & 0x01;
  }

  return ones % 2;
}

void sw_uart_transmite(due_sw_uart *uart, char data){

    //Envia bit de start e esperando 1 período de clock
    Serial.println("Start Bit");
    digitalWrite(uart -> pin_tx, LOW); 
    _sw_uart_wait_T(uart);

    // Envia caracter
    for(int i = 0; i < 8; i++) {
      char bit_data;
  
      // Enviando um bit por vez.
      // Realizando um SHIFT RIGHT nos dados em conjunto com uma operação AND para enviar apenas um bit 
      // menos significativo por vez.
      bit_data = (data >> i) & 0x01;
      digitalWrite(uart->pin_tx, bit_data);
      _sw_uart_wait_T(uart);                           // Esperar 1 periodo clock
      
    }

    // Enviando bit de paridade
    Serial.println("PARITY bit");
    int bit_paridade = calc_even_parity(data);   // calculando paridade do dado que sera enviado
    //uart-> paritybit = bit_paridade
    digitalWrite(uart->pin_tx, bit_paridade);
    _sw_uart_wait_T(uart);                            // Esperar 1 periodo clock

    
    // Enviando STOP bit
    Serial.println("STOP bit");
    digitalWrite(uart->pin_tx, uart->stopbits);
}

// MCK 21MHz
void _sw_uart_wait_half_T(due_sw_uart *uart) {
  for(int i = 0; i < 1093; i++)
    asm("NOP");
}

void _sw_uart_wait_T(due_sw_uart *uart) {
  _sw_uart_wait_half_T(uart);
  _sw_uart_wait_half_T(uart);
}
