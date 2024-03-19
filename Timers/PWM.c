/*
 * File:   PWM.c
 * Author: askar
 *
 * Created on 28 November, 2023, 4:14 PM
 */


#include <pic18.h>
void main(void) {
    
    TRISC=0X00; // O/P
    T2CON=0X7F; // Timer2 CONTROL register(INTERNAL REGISTER)
    PR2=255;
    CCP1CON=0X0F;

    while(1){
        
    }
            
    return;
}