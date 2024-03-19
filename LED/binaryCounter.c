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
    TRISD=0X00;
    
    
    for(i=0;i<129;i++){
        PORTD=0x00+i;
        delay();
    }
    
    return;
}
void delay(){
    int i,j;
    for(i=0;i<500;i++){
        for(j=0;j<500;j++);
    }
}

