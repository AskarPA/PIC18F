/*
 * File:   1_display.c
 * Author: askar
 *
 * Created on 21 November, 2023, 4:20 PM
 */


#include <pic18.h>

void delay();
void cmd(char a);
void data(char a);
void main(void) {
    TRISC=0X00;
    TRISD=0X00;
    char str[]="HELLO WORLD";
    cmd(0x38); //2 lines
    cmd(0x01); //clear display
    cmd(0x06); //increment cursor
    cmd(0x0E); //display ON cursor blinking
    cmd(0x80); //force cursor to the beginning
    for(int i=0;str[i]!='\0';i++){
        data(str[i]);
    }
    while(1){
        
    }
    

    return;
}

void delay(){
    int i,j;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++);
    }
}

void cmd(char a){
    PORTD=a;//DATA PIN
    RC0=0;//RS PIN
    RC1=1;//ENABLE PIN
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