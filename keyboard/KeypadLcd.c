/*
 * File:   2_lcdPointer.c
 * Author: askar
 *
 * Created on November 23, 2023, 2:15 PM
 */


#include <pic18.h>

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

void main(void) {
    ADCON1=0X0F;
    TRISB=0XF0;
    TRISC=0X00;
    TRISD=0X00;
  
    
    cmd(0x38); //2 lines
    cmd(0x01); //clear display
    cmd(0x06); //increment cursor
    cmd(0x0E); //display ON cursor blinking
    cmd(0x80); //force cursor to the beginning
    
    
    while(1){
         PORTB=0X0E;  //00001110
         if(RB4==0){
             data('0');
             while(RB4==0){
             }}  
         
         if(RB5==0){
             data('1');
             while(RB5==0){
             }
         }
                  if(RB6==0){
             data('2');
             while(RB6==0){
             }
         }
                  if(RB7==0){
             data('3');
             while(RB7==0){ 
             }
                  }
  PORTB=0X0D;  //00001101
         if(RB4==0){
             data('4');

             while(RB4==0){
                 
             }
         }
         if(RB5==0){
             data('5');
             

             while(RB5==0){
                 
             }
         }
                  if(RB6==0){
             data('6');
             while(RB6==0){
                 
             }
         }
                  if(RB7==0){
             data('7');
             while(RB7==0){
                 
             }
         }
  PORTB=0X0B;  //00001011
         if(RB4==0){
             data('8');
             while(RB4==0){
             }}  
         
         if(RB5==0){
             data('9');
             while(RB5==0){
             }
         }
                  if(RB6==0){
             data('A');
             while(RB6==0){
             }
         }
                  if(RB7==0){
             data('B');
             while(RB7==0){ 
             }
                  }
  PORTB=0X07;  //00000111
         if(RB4==0){
             data('C');
             while(RB4==0){
             }}  
         
         if(RB5==0){
             data('D');
             while(RB5==0){
             }
         }
                  if(RB6==0){
             data('E');
             while(RB6==0){
             }
         }
                  if(RB7==0){
             data('F');
             
             while(RB7==0){ 
             }
                  }
    
    }
    return;
}


