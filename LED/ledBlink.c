/*
 * File:   ledBlink.c
 * Author: askar
 *
 * Created on 20 November, 2023, 2:13 PM
 */


#include <pic18.h>
void delay();
void main(void) {
    TRISB=0X00;
    while(1){
    PORTB=0XFF;
    delay();
    PORTB=0X00;
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
