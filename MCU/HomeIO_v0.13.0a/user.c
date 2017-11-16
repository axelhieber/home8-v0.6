/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

/**********************************************/
/*                  CONFIG                    */
#define Timer2Scaler 40  // 50HZ*125 = 6250 Hz = CLK/16*1*x*4 - 16MHz CLK

/**********************************************/
/*                  DEFIEN                    */
#define TLL232 1


void InitPort(void)             {
    
/*A PORT*/
    ANSELA=0x00;
    PORTA=0x00;
    TRISA=0xFF;
    TRISAbits.TRISA0=1;     // Switch(SW1.0) -> Input   19
    TRISAbits.TRISA1=1;     // Switch(SW1.1) -> Input   20
    TRISAbits.TRISA2=0;     // Not Conneted  -> Output  21
    TRISAbits.TRISA3=0;     // Not Conneted  -> Output  22 
    TRISAbits.TRISA4=0;     // OneWire       -> Output  23
    TRISAbits.TRISA5=0;     // Not Conneted  -> Output  24
    //TRISAbits.TRISA6=1;   // Oszilator                33
    //TRISAbits.TRISA7=1;   // Oszilator                32
    
/*B PORT*/
    ANSELB=0x00;
    PORTB=0x00;
    TRISB=0xFF;             // Optocoupler   -> Input   {9 bis 17}\13
    
/*C PORT*/
    ANSELC=0x00;
    PORTC=0x00;
    TRISC=0xFF;
    TRISCbits.TRISC0=0;     // Relay 0       -> Output  34
    TRISCbits.TRISC1=0;     // Relay 1       -> Output  35
    TRISCbits.TRISC2=0;     // Relay 2       -> Output  36
    TRISCbits.TRISC3=0;     // Relay 3       -> Output  37 
    TRISCbits.TRISC4=1;     // Optocoupler   -> Input   42
    TRISCbits.TRISC5=0;     // Not Conneted  -> Output  43
    TRISCbits.TRISC6=1;     // TX1           -> Output  44
    TRISCbits.TRISC7=1;     // RX1           -> Input    1
    
/*D PORT*/
    ANSELD=0x00;
    PORTD=0x00;
    TRISD=0xFF;
    LATE=0x00;
    TRISDbits.TRISD0=0;     // Relay 4       -> Output  38
    TRISDbits.TRISD1=0;     // Relay 5       -> Output  39
    TRISDbits.TRISD2=0;     // Relay 6       -> Output  40
    TRISDbits.TRISD3=0;     // Relay 7       -> Output  41 
    TRISDbits.TRISD4=0;     // RST           -> Output   2
    TRISDbits.TRISD5=0;     // CH_PD         -> Output   3
    TRISDbits.TRISD6=0;     // TX2           -> Output   4
    TRISDbits.TRISD7=1;     // RX2           -> Input    5
  
/*E PORT*/
    ANSELE=0x00;
    PORTE=0x00;
    TRISE=0xFF;
    TRISEbits.TRISE0=0;     // Not Conneted  -> Output  25
    TRISEbits.TRISE1=0;     // LED 0         -> Output  26
    TRISEbits.TRISE2=0;     // LED 1         -> Output  27

    
    
    
    
    
}
void InitTimer2(void)           {
    T2CON=0x00;
    T2CONbits.T2OUTPS=0b0000;  // Prescaler  x16
    T2CONbits.T2CKPS =0b11;    // Postscaler x16
    
    TMR2=0x00;
    PR2=Timer2Scaler;
    T2CONbits.TMR2ON=1;
    
    NOP();
    
}
void InitInterupt(void)         {
    IPR1bits.TMR2IP = 1;        // Set Timer 2 to high priority Interupt
    PIE1bits.TMR2IE = 1;        // Enalbel Timer 2 Interupt
    PIR1bits.TMR2IF = 0;        // Clear Timer 2 interupt Flage
    
    IPR3bits.RC2IP=1;
    PIE3bits.RC2IE=1;
    PIR3bits.RC2IF=0;
     
    PIR1=0x00;
    PIR2=0x00;
    PIR3=0x00;
    RCONbits.IPEN   = 0;        // Enable priority levels on interrupts
    INTCONbits.GIEH = 0;        // Enables all high priority interrupts
    INTCONbits.GIEL = 0;        // Disables all low priority interrupts  
    
}
void InitUART1(char UART_MODE)  {
    NOP();
    
    
    /**PORT D E F I N I T I O N S ****************************************************/

//UART PORT DEFINITIONS
#define UART_RX_DIRECTION   TRISCbits.TRISC7
#define UART_TX_DIRECTION   TRISCbits.TRISC6
#define UART_RX_STATUS		RCSTA
#define UART_TX_STATUS		TXSTA
    
}
void InitUART2(char UART_MODE)  {
    TXSTA2bits.TXEN2=0;
    TXSTA2bits.BRGH2=0;
    TXSTA2bits.SYNC2=0;
    RCSTA2bits.SPEN=1;
    BAUDCON2bits.BRG162=0;
    SPBRG2=25;

    NOP();
    NOP();
    
        TXSTA2bits.TXEN2=1;
        RCSTA2bits.CREN2=1;

}
void InitOneWire(void)          {
    NOP();
}

void InitApp(void)
{
        
    InitPort();                 // Init Ports ANSEL, TRIS ... 
    //InitTimer2();
    //InitOneWire();
    //InitUART1(TLL232);          //TLL232 TLL422
    // InitUART2(TLL232);          //TLL232
    //InitInterupt();
    
    
    
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
}

