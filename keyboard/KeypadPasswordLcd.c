#include <pic18.h>
void display(const char *p);
char password2[10];
char  password[10]="1234";
int i;
int flag=0;

void delay (void)
{
    int i,j;
    for(i=0;i<200;i++)
    {
        for(j=0;j<200;j++);
    }
}
void cmd(char a)
{
    
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
}
void data(char a)
{
    PORTD=a;
    RC0=1;
    RC1=1;
    delay();
    RC1=0;
  password2[i]=a;
        i++;
   
}
void main(void) 
{
    ADCON1=0X0F;
    TRISB=0XF0;
    TRISC=0X00;
    TRISD=0X00;
    TRISA=0X00;
    cmd(0x38);
    cmd(0x06);
    cmd(0x0E);
    cmd(0x80);
    

    while(1)
    {
       
        PORTB=0X0E;
        if(RB4==0)
        {
            data('0');
            while(RB4==0)
            {
                
            }
            
        }
        if(RB5==0)
        {
            data('1');
            while(RB5==0)
            {
                
            }
            
        }
        if(RB6==0)
        {
            data('2');
            while(RB6==0)
            {
                
            }
         
        }
        if(RB7==0)
        {
            data('3');
            while(RB7==0)
            {
                
            }
        }
        PORTB=0X0D;
        if(RB4==0)
        {
            data('4');
            while(RB4==0)
            {
                
            }
        }
        if(RB5==0)
        {
            data('5');
            while(RB5==0)
            {
                
            }
            
        }
        if(RB6==0)
        {
            data('6');
            while(RB6==0)
            {
                
            }
         
        }
        if(RB7==0)
        {
            data('7');
            while(RB7==0)
            {
                
            }
       
        }
        PORTB=0X0B;
        if(RB4==0)
        {
            data('8');
            while(RB4==0)
            {
                
            }
        }
        if(RB5==0)
        {
            data('9');
            while(RB5==0)
            {
                
            }
            
        }
        if(RB6==0)
        {
            data('A');
            while(RB6==0)
            {
                
            }
         
        }
        if(RB7==0)
        {
            data('B');
            while(RB7==0)
            {
                
            }
       
        }
        PORTB=0X07;
        if(RB4==0)
        {
            data('C');
            while(RB4==0)
            {
                
            }
        }
        if(RB5==0)
        {
            data('D');
            while(RB5==0)
            {
                
            }
            
        }
        if(RB6==0)
        {
            data('E');
            while(RB6==0)
            {
                
            }
         
        }
        if(RB7==0)
        {
            data('F');
            while(RB7==0)
            {
                
            }
       
        }
        if(i==4){
            cmd(0xc0);
        for(i=0;i<4;i++)
        {
        if(password2[i]==password[i])
        {
        flag++;
        }
        }
    if(flag==4)
        {
        display("access granted");
        while(1)
        {
        PORTA=0X01;
        delay();
        
        
       
        }}
    else
    {
        display("access denied");
        PORTA=0X02;
         
    } 
        
   }
    }
       
 return;
}
void display(const char *p)
{
    while(*p!='\0')
    {
        data(*p);
        p++;
    }
}