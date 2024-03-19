/*
 * File:   EUSART_TX.c
 * Author: askar
 *
 * Created on 29 November, 2023, 4:13 PM
 */


#include <pic18.h>
void transmit(char a);
void main(void) {
    
    TRISC = 0X80; //1000 0000 (TX-OUTPUT & RX INPUT 
    RCSTA = 0X90;
    TXSTA = 0X24;
    SPBRG = 129;
    transmit('S');
    while(1){
  
    }
    return;
}
void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
    TXIF = 0;
}
