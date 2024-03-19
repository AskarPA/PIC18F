/*
 * File:   oddEvenBlink.c
 * Author: askar
 *
 * Created on 20 November, 2023, 3:23 PM
 */


#include <pic18.h>
void delay();
void main(void) {
        TRISC = 0X00;
        
        while(1){
        PORTC = 0XAA;
        delay();
        
        PORTC = 0X55;
        delay();
    return;
        }
}
void delay(){
    int i,j;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++);
    }
}
