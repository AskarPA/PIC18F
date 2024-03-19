/*
 * File:   timer0.c
 * Author: askar
 *
 * Created on 27 November, 2023, 4:37 PM
 */


#include <pic18.h>
void time();
void main(void) {
    ADCON1=0X0F;
    T0CON=0XC7; //Timer0 CONTROL register
    TRISB=0X00;
    
    while(1){
        PORTB=0XFF;
        time();
        PORTB=0X00;
        time();
    }
            
    return;
}
void time(){
    for(int i=0;i<100;i++){
        while(TMR0IF==0);
              TMR0IF=0;
            TMR1L=60;
}
}