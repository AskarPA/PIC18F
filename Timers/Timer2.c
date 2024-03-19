/*
 * File:   timer0.c
 * Author: askar
 *
 * Created on 27 November, 2023, 4:37 PM
 */


#include <pic18.h>
void time();
void main(void) {
    ADCON1=0X0F; // ADC
    T2CON=0X7F; // Timer1 CONTROL register
    TRISB=0X00; // O/P
    
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
        while(TMR2IF==0);
        PR2 = 195;
              TMR2IF=0;
            
}
}