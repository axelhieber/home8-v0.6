/*
 * File:   Led1_main.c
 * Author: axel
 *
 * Created on July 5, 2017, 6:42 PM
 */
#include "app_def.h"

#ifdef LED

#if defined(__XC)
    #include <xc.h>        //XC8 General Include File 
#elif defined(HI_TECH_C)
    #include <htc.h>       // HiTech General Include File 
#elif defined(__18CXX)
    #include <p18cxxx.h>   // C18 General Include File
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        // For uint8_t definition 
#include <stdbool.h>       // For true/false definition 

#endif



#include "configuration_bits.h"


#include "board_def.h"
#include "user.h"          // User funct/params, such as InitApp 
#include "hadwareProfile.h"
#include "mapIO.h"
#include "data_types.h"
#include "externvar.h"
#include "hadware_interface.h"
#include "board_interface.h"
#include "mcc.h"

#include"led_color_interups.h"

void init(void);



void main(void)
{
    int i=0;
    // Configure the oscillator for the device 
    InitApp();
    SYSTEM_Initialize();
    
    TRISD = 0xBD;
    ANSELD = 0x3F;
    WPUB = 0xFF;
    INTCON2bits.nRBPU = 0;
    RCONbits.IPEN = 0;
    init();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    // Initialize I/O and Peripherals for application 
    



    TMR6_SetInterruptHandler(LedWhiteFade);
    
    NOP();
    LATEbits.LE2=0;
            
            
    while(1)
    {

        
        TXREG2 = 'A';
        for(i=100000;i<=0;i++)
            NOP();
       // EUSART2_Write(10);
        // Add your application code

        
        WNOP();
    }

}

void init(void)
{
    TMR6_Initialize();
    TMR4_Initialize();
    
    EPWM1_Initialize();
    EPWM2_Initialize();
    EPWM3_Initialize();
    PWM4_Initialize();
    
    EUSART2_Initialize();
            
    
    EPWM1_LoadDutyValue(0xFFF); //Green
    EPWM2_LoadDutyValue(0xFFF); //RED
    EPWM3_LoadDutyValue(0xFFF); //White
    PWM4_LoadDutyValue(0xFFF); //BLUE
}


#endif