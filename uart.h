#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED



#endif // UART_H_INCLUDED


void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);
