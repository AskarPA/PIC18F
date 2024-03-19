/*
 * File:   RX_TX_PASSWORD.c
 * Author: askar
 *
 * Created on 1 December, 2023, 9:28 AM
 */




#include <pic18.h>
void transmit(char a);
void display(const char *p);
char recieve();
char c;
char password[10]="1001";
char store[10];
int flag=0;
int i;


void main(void) {
    
    TRISC = 0X80; //1000 0000 (TX-OUTPUT & RX INPUT)
    RCSTA = 0X90; //reciever status
    TXSTA = 0X24; //transmit status
    SPBRG = 129; //
    
    
   
    while(1)
        {
         
         for(i=0;i<4;i++){
             c=recieve(); 
             transmit(c);
             store[i]=c;
         
         }
             for(i=0;i<4;i++){
    if(password[i]==store[i]){
        flag++;
    }
             }
         if(flag==4)
        {
        
        display("\raccess granted");
         }
         else
    {
        display("\raccess denied");
         
    }
         
    }
    return;
}


void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
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