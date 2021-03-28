/*
 * UART.c
 *
 * Created: 24/01/2021 04:20:56 م
 *  Author: Smart
 */ 
#include "UART.h"

void Uart_Init(){
	//8BIT_no par _ 1 Bit stop
	UCSRB |= ((1<<RXEN)|(1<<TXEN)); // Bit 4 – RXEN: Receiver Enable &• Bit 3 – TXEN: Transmitter Enable
    UCSRC |=((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));  //Bit 7 – URSEL: Register Select &• Bit 2:1 – UCSZ1:0: Character Size   8-bit    UBRRL = (char)MyUBRR;              //USART Baud Rate Registers – UBRRL and UBRRH
	UBRRH = (char)(MyUBRR >> 8);      // char for casting
	
	
	
	
}
void Uart_TxChar(char data){
	while(((UCSRA >> UDRE)&1) == 0); //Bit 5 – UDRE: USART Data Register Empty
	//while(!((UCSRA >> UDRE)&1));
	UDR = data ;
	
}
  char Uart_RxChar (){
	while(((UCSRA >> RXC)&1) == 0);  // • Bit 7 – RXC: USART Receive Complete
	return UDR ;
}
void Uart_TxString(char * string){
	unsigned char i=0;
	while(string[i] !='\0'){
		Uart_TxChar(string[i]);
		i++;
	}
}