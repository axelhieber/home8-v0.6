#include "data_types.h"
#include "hadware_interface.h"
#include "board_def.h"


void pushOutput(char OUT , char change)
{    
#if defined(KG) || defined(EG) || defined(OG) || defined(DG) || defined(HEIZUNG) || defined(TEST)

    union bit_byte tOut;
     
    tOut.byte=OUT;
    
    PORTCbits.RC0=tOut.u.bit0;
    PORTCbits.RC1=tOut.u.bit1;
    PORTCbits.RC2=tOut.u.bit2;
    PORTCbits.RC3=tOut.u.bit3;
    
    PORTDbits.RD0=tOut.u.bit4;
    PORTDbits.RD1=tOut.u.bit5;
    PORTDbits.RD2=tOut.u.bit6;
    PORTDbits.RD3=tOut.u.bit7;
 #endif

    
}

char getInputPin(char in)
{
#if defined(KG) || defined(EG) || defined(OG) || defined(DG) || defined(HEIZUNG) || defined(TEST)
    switch(in)
    {
        case 0 : return(readPortPin(INPUT_0_PORT,INPUT_0_PIN));
        case 1 : return(readPortPin(INPUT_1_PORT,INPUT_1_PIN));
        case 2 : return(readPortPin(INPUT_2_PORT,INPUT_2_PIN));
        case 3 : return(readPortPin(INPUT_3_PORT,INPUT_3_PIN));
        case 4 : return(readPortPin(INPUT_4_PORT,INPUT_4_PIN));
        case 5 : return(readPortPin(INPUT_5_PORT,INPUT_5_PIN));
        case 6 : return(readPortPin(INPUT_6_PORT,INPUT_6_PIN));
        case 7 : return(readPortPin(INPUT_7_PORT,INPUT_7_PIN));
        case 8 : return(0);
        
    }
#endif
    return(0);
}

void setLED(char LED_PORT, char LED_PIN , char value)
{
    
}
void setLED1(char value)
{    
    setPortPin(LED1_PORT,LED1_PIN,value);
}
void setLED2(char value)
{
    setPortPin(LED2_PORT,LED2_PIN,value);
}