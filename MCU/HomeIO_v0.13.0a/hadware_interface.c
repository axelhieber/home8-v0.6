#include <xc.h>
#include "data_types.h"

//    union bit_byte data;
//    union nipple_byte data;

char readPort(char Port)
{
    switch(Port)
    {
        case 'A' : return(PORTA);
        case 'B' : return(PORTB);
        case 'C' : return(PORTC);
        case 'D' : return(PORTD);
        case 'E' : return(PORTE);
       // case 'F' : PORTF;
    }
    return 0;
}

char readPortPin(char Port, char Pin)
{
    union bit_byte data;
    data.byte=readPort(Port);
    
    switch(Pin)
    {
        case 0 : return(data.u.bit0);
        case 1 : return(data.u.bit1);
        case 2 : return(data.u.bit2);
        case 3 : return(data.u.bit3);
        case 4 : return(data.u.bit4);
        case 5 : return(data.u.bit5);
        case 6 : return(data.u.bit6);
        case 7 : return(data.u.bit7);
        
    }
    return(0);
}



char readPortNippel(char Port, char LowerUpper)
{
    union nipple_byte data;
    data.byte=readPort(Port);
    
    switch(LowerUpper)
    {
        case 'l' : return(data.u.nippleLower);
        case 'u' : return(data.u.nippleUpper);
    }
    return(0);
}
void setPort(char Port, char Data)
{
    switch(Port)
    {
        case 'A' : PORTA=Data;
        case 'B' : PORTB=Data;
        case 'C' : PORTC=Data;
        case 'D' : PORTD=Data;
        case 'E' : PORTE=Data;
       // case 'F' : PORTF;
    }
}

void setPortPin(char Port, char Pin, char Data)
{
 
  //  union bit_byte data;
  //  data.byte=readPort(Port);
    switch(Port)
    {
        case 'A':
            switch(Pin)
            {
                case 0 : PORTAbits.RA0=Data;break;
                case 1 : PORTAbits.RA1=Data;break;
                case 2 : PORTAbits.RA2=Data;break;
                case 3 : PORTAbits.RA3=Data;break;
                case 4 : PORTAbits.RA4=Data;break;
                case 5 : PORTAbits.RA5=Data;break;
                case 6 : PORTAbits.RA6=Data;break;
                case 7 : PORTAbits.RA7=Data;break;

            }
            break;
        case 'B':
            switch(Pin)
            {
                case 0 : PORTBbits.RB0=Data;break;
                case 1 : PORTBbits.RB1=Data;break;
                case 2 : PORTBbits.RB2=Data;break;
                case 3 : PORTBbits.RB3=Data;break;
                case 4 : PORTBbits.RB4=Data;break;
                case 5 : PORTBbits.RB5=Data;break;
                case 6 : PORTBbits.RB6=Data;break;
                case 7 : PORTBbits.RB7=Data;break;

            }
            break;
        case 'C':
            switch(Pin)
            {
                case 0 : PORTCbits.RC0=Data;break;
                case 1 : PORTCbits.RC1=Data;break;
                case 2 : PORTCbits.RC2=Data;break;
                case 3 : PORTCbits.RC3=Data;break;
                case 4 : PORTCbits.RC4=Data;break;
                case 5 : PORTCbits.RC5=Data;break;
                case 6 : PORTCbits.RC6=Data;break;
                case 7 : PORTCbits.RC7=Data;break;

            }
            break;
        case 'D':
            switch(Pin)
            {
                case 0 : PORTDbits.RD0=Data;break;
                case 1 : PORTDbits.RD1=Data;break;
                case 2 : PORTDbits.RD2=Data;break;
                case 3 : PORTDbits.RD3=Data;break;
                case 4 : PORTDbits.RD4=Data;break;
                case 5 : PORTDbits.RD5=Data;break;
                case 6 : PORTDbits.RD6=Data;break;
                case 7 : PORTDbits.RD7=Data;break;

            }
            break;
        case 'E':
            switch(Pin)
            {
                case 0 : PORTEbits.RE0=Data;break;
                case 1 : PORTEbits.RE1=Data;break;
                case 2 : PORTEbits.RE2=Data;break;
                case 3 : PORTEbits.RE3=Data;break;
//                case 4 : PORTEbits.RE4;break;
//                case 5 : PORTEbits.RE5;break;
//                case 6 : PORTEbits.RE6;break;
//                case 7 : PORTEbits.RE7;break;

            }
            break;
    }
}


void setPortNippel(char Port, char LowerUpper, char Data)
{
        switch(Port)
    {
        case 'A':
            switch(LowerUpper)
            {
                case 0 : PORTAbits.RA0;break;
                case 1 : PORTAbits.RA1;break;
                case 2 : PORTAbits.RA2;break;
                case 3 : PORTAbits.RA3;break;
                case 4 : PORTAbits.RA4;break;
                case 5 : PORTAbits.RA5;break;
                case 6 : PORTAbits.RA6;break;
                case 7 : PORTAbits.RA7;break;

            }
            break;
        case 'B':
            switch(LowerUpper)
            {
                case 0 : PORTBbits.RB0;break;
                case 1 : PORTBbits.RB1;break;
                case 2 : PORTBbits.RB2;break;
                case 3 : PORTBbits.RB3;break;
                case 4 : PORTBbits.RB4;break;
                case 5 : PORTBbits.RB5;break;
                case 6 : PORTBbits.RB6;break;
                case 7 : PORTBbits.RB7;break;

            }
            break;
        case 'C':
            switch(LowerUpper)
            {
                case 0 : PORTCbits.RC0;break;
                case 1 : PORTCbits.RC1;break;
                case 2 : PORTCbits.RC2;break;
                case 3 : PORTCbits.RC3;break;
                case 4 : PORTCbits.RC4;break;
                case 5 : PORTCbits.RC5;break;
                case 6 : PORTCbits.RC6;break;
                case 7 : PORTCbits.RC7;break;

            }
            break;
        case 'D':
            switch(LowerUpper)
            {
                case 0 : PORTDbits.RD0;break;
                case 1 : PORTDbits.RD1;break;
                case 2 : PORTDbits.RD2;break;
                case 3 : PORTDbits.RD3;break;
                case 4 : PORTDbits.RD4;break;
                case 5 : PORTDbits.RD5;break;
                case 6 : PORTDbits.RD6;break;
                case 7 : PORTDbits.RD7;break;

            }
            break;
        case 'E':
            switch(LowerUpper)
            {
                case 0 : PORTEbits.RE0;break;
                case 1 : PORTEbits.RE1;break;
                case 2 : PORTEbits.RE2;break;
                case 3 : PORTEbits.RE3;break;
//                case 4 : PORTEbits.RE4;break;
//                case 5 : PORTEbits.RE5;break;
//                case 6 : PORTEbits.RE6;break;
//                case 7 : PORTEbits.RE7;break;

            }
            break;
    }
}




void WNOP()
{
    NOP();
}


char UART_Receive(char Channel)
{
    switch(Channel)
    {
        case 1 : return RCREG1;
        case 2 : return RCREG2;
    }
    return 0;
            
}