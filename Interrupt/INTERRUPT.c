/*
 * File:   interrupt.c
 * Author: askar
 *
 * Created on 11 December, 2023, 3:18 PM
 */


#include <pic18.h>

void delay(){
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++);
    }
}

void main(void) {
    
    GIE=1;
    PEIE=1;
    INT0IE=1;
    
    TRISB=0XFF;
    TRISC=0X00;
    TRISD=0X00;
    ADCON1=0X0F;
    while(1){
        PORTD=0XFF;
        delay();
        PORTD=0X00;
        delay();
    }
    return;
}
void interrupt __isr(void){
    if(INT0IF==1){
        for(int i=0;i<20;i++){
        PORTC=~PORTC;
        delay();
        }
        INT0IF=0;
    }
}