/*
 * File:   5blink.c
 * Author: askar
 *
 * Created on 21 November, 2023, 2:01 PM
 */


#include <pic18.h>

void delay();

void main(void) {
    ADCON1=0X0F;
    TRISC = 0X00;
    TRISB = 0XFF;
    
    while(1){
        if(RB0==0){
            PORTC=0XFF;
        }
        else{
            PORTC=0X00;
        }
    }
    return;
}
