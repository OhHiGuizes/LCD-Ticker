#include "uart.h"
#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

char inputString[16];
int pos = 0;


int main(void){
    USART_init();
    LCD_Init();
    UCSR0B |= (1 << RXCIE0);
    sei();
    USART_putstring("Ready!");
    while(1){    }
    return 0;
}
ISR(USART_RX_vect){
    if(inputString[15] != 0){
        for(int i = 0; i <= 14; i++){
            inputString[i] = inputString[i+1];
        }
        inputString[15] = UDR0;
        LCD_Command(0x01);
        LCD_String(inputString);
    }
    else{
        LCD_Clear();
        inputString[pos] = UDR0;
        pos++;
        LCD_Command(0x90 - pos);
        LCD_String(inputString);
        //LCD_Command(0x18);
    }

    _delay_ms(300);
    USART_putstring("OK!");

    //char c;
    //c = UDR0;
    //UDR0 = c;
}
