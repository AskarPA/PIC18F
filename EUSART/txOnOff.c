 /*
 * File:   EUSART_LCD.c
 * Author: askar
 *
 * Created on 4 December, 2023, 2:22 PM
 */

#include <pic18.h>
void delay();
void cmd(char a);
void transmit(char a);
void display(const char *p);
char recieve();
char c,d;
void data(char a);



void main(void) {
    
    TRISC = 0X80; //1000 0000 (TX-OUTPUT & RX INPUT)
    TRISD = 0X00;
    RCSTA = 0X90; //recieve status
    TXSTA = 0X24;
    SPBRG = 129;
    cmd(0x38); //2 lines
    cmd(0x01); //clear display
    cmd(0x06); //increment cursor
    cmd(0x0E); //display ON cursor blinking
    cmd(0x80); //force cursor to the beginning
    int f=0;
    while(1){
        d=recieve();
   
    
    if(d=='#'){
        
        f=0;
        
    }
        if(f==1){
        
            transmit(d);
            
    
        }
         if(d=='*'){
        
            f=1;
            
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
    RCIF=0;
    return RCREG;     
}

void display(const char *p){
    while(*p!='\0'){
        transmit(*p);
        p++;
    }
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