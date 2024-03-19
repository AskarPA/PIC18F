/*
 * File:   shiftBlink.c
 * Author: askar
 *
 * Created on 20 November, 2023, 3:57 PM
 */


#include <pic18.h>
void delay();
void main(void) {
    int i;
    TRISB=0X00;
    
    
    for(i=0;i<8;i++){
        PORTB=0x01<<i;
        delay();
    }
    
    return;
}
void delay(){
    int i,j;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++);
    }
}

