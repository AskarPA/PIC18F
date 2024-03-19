/*
 * File:   motorRotation.c
 * Author: askar
 *
 * Created on 20 November, 2023, 7:39 PM
 */


#include <pic18.h>
void main(void) {
    ADCON1=0X08;
    TRISC = 0X00;
    TRISB = 0XFF;
    while(1){
        if(RB0==0){
            PORTC = 0X1D;
        }
        if(RB1==0){
            PORTC = 0X2E;                                                                                                                                                                           ;                                                                                                                                    ;
        }
        if(RB2==0){
            PORTC = 0X2D;                                                                                                                                                                                                                                                                                                                 ;                                                                                                                                    ;
        }
        if(RB3==0){
            PORTC = 0X2E;                                                                                                                                                                                                                                                                                                                 ;                                                                                                                                    ;
        }
        
    }
    
    return;
}
