/*
 * File:   2_lcdswitchrotation.c
 * Author: askar
 *
 * Created on November 23, 2023, 2:15 PM
 */


#include <pic18.h>

void delay();
void cmd(char a);
void data(char a);
void display(const char *a);

void main(void) {
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0X00;
    ADCON1=0X0F;
    TRISA=0XFF;
    
    cmd(0x38); //2 lines
    cmd(0x01); //clear display
    cmd(0x06); //increment cursor
    cmd(0x0E); //display ON cursor blinking
    cmd(0x80); //force cursor to the beginning
    if(RA0==0){
        display("CLOCKWISE");
        PORTB=0X05;
    }
    else if(RA1==0){
        display("ANTI-CLOCKWISE");
        PORTB=0X06;
    }
    else{
        display("PRESS ANY SWITCH");
        PORTB=0X00;
    }
    return;
}
void display(const char *p){
    while(*p!='\0'){
        data(*p);
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