/*
 * File:   euart.c
 * Author: askar
 *
 * Created on 11 December, 2023, 1:56 PM
 */

#include <pic18.h>
#include<stdio.h>

void delay();
void cmd(char a);
void data(char a);
void transmit(char a);
void display(const char *a);
int b,i;

int arr[20];

void main(void) {
    ADCON0=0X01;
    ADCON1=0X00;
    ADCON2=0X86;
    TRISA=0XFF;
    TRISD=0X00;
    TRISC = 0X80; //1000 0000 (TX-OUTPUT & RX INPUT 
    RCSTA = 0X90;
    TXSTA = 0X24;
    SPBRG = 129;
    
    cmd(0x38); //2 lines
    cmd(0x01); //clear display
    cmd(0x06); //increment cursor
    cmd(0x0E); //display ON cursor blinking
    cmd(0x80); //force cursor to the beginning
    
   while(1){
        GODONE=1;
        while(GODONE==1);
        b=ADRESL;
        b=b+(ADRESH<<8);
        sprintf(arr,"%d",b);
        
//            for(i=0;i<4;i++){
//            arr[3-i]=(b%10)+48;
//            b=b/10;
//            }
//        for(i=0;i<4;i++){
            display(arr);
//            
//            
//        }
       transmit('\r');
       cmd(0x80);
    }
    
    return;
}
void transmit(char a){
    TXREG = a;
    while(TXIF == 0);
    TXIF = 0;
}
void display(const char *p){
    while(*p!='\0'){
        transmit(*p);
        p++;
    }
}

void delay(){
for(int i=0;i<200;i++){
    for(int j=0;j<200;j++);
}
}
void cmd(char a){
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
}
void data(char a){
    PORTD=a;
    RC0=1;
    RC1=1;
    delay();
    RC1=0;
}


