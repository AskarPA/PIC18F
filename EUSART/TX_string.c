/*
 * File:   TX_string.c
 * Author: askar
 *
 * Created on 30 November, 2023, 1:53 PM
 */


#include <pic18.h>
void transmit(char a);
void display(const char *p);
char recieve();
char c;


void main(void) {
    
    TRISC = 0X80; //1000 0000 (TX-OUTPUT & RX INPUT)
    RCSTA = 0X90; //recieve status
    TXSTA = 0X24;
    SPBRG = 129;
    
    display("HELLO WORLD");
   
    while(1)
        {
        
         //c=recieve(); 
        // transmit(c);
        }
    return;
}


void transmit(char a){
    
    while(TXIF == 0);
    TXREG = a;
    TXIF = 0;
}
char recieve(){
    while(RCIF==0);
    return RCREG;     
}

void display(const char *p){
    while(*p!='\0'){
        transmit(*p);
        p++;
    }
}