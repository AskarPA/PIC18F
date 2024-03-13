/*
 * File:   5blink.c
 * Author: askar
 *
 * Created on 21 November, 2023, 2:01 PM
 */


#include <pic18.h>

void delay();
void main(void) {
    ADCON1 =0X08;
    TRISC = 0X00;
    TRISB = 0XFF;
    int i;
    
    while(1){
        if(RB0==0){
            PORTC=0XFF;
            delay();
        }
        
        if(RB1==0){
                PORTC=0XAA;
                delay();
                PORTC=0X55;
                delay();
            } 
        if(RB2==0){
            for(i=0;i<8;i++){
                PORTC=0X01<<i;
                delay();
            }
        }
        if(RB3==0){
            PORTC=0XFF;
            delay();
            PORTC=0X00;
            delay();
        }
        
        }
    
    return;
}
void delay(){
    int i,j;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++);
    }
}
