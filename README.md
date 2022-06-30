<div align="center">
  <h2> UART-Serialization </h2>
</div>



<h4> ⚡️ Descrição</h4>

<div>

O objetivo desse projeto é a serialização de um byte e enviá-lo através de 1 pino digital qualquer de um Arduino para outro Arduino, que receberá a mensagens no padrão UART através de outro pino digital qualquer. Dessa forma, criasse um algoritmo que produza a saída UART em um pino digital
genérico, nao utilizando, desse modo, os pinos **Tx** e **Rx** do Arduino. 
<br>
  
Para um exmeplo prático do funcionamento imagine que deseja enviar o caracter "A" , para isso ele é codificado por meio da tabela ASCII e o envio de bits segue o frame UART definido previamente no código.

<div>

<h4> ⚙️ Configurações Padrões e Frame UART </h4>
  
O padrão inicial de configuração do fram UART é definido a seguir:
  
- 1 **PARITY** bit
  
- 1 **START** bit
  
- 1 **STOP** bit
  
- Baudrate de **9600 bits/s** 
  
<h4> 📍️ Montagem </h4>





<h4> 💻️ Funcionamento do código </h4>
