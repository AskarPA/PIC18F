/*
 * File:   tIMERsWITCH.c
 * Author: askar
 *
 * Created on 29 November, 2023, 2:40 PM
 */


#include <pic18.h>
void main(void) {
    
    TRISC=0X00; // OUTPUT
    TRISD = 0XFF; //INPUT
    T2CON=0X7F; // Timer2 CONTROL register(INTERNAL REGISTER)
    PR2=255;
    CCP1CON=0X0F; 

    while(1){
        
        if(RD0 == 0){
            CCPR1L=0X80; // 50% DUTY CYCLE
        }
        if(RD1 == 0){
            CCPR1L=0XD0; //75% DUTY CYCLE
        }
        if(RD2 == 0){
            CCPR1L=0X40; //25% DUTY CYCLE
        }
        
    }
            
    return;
}