/*
 * File:   Led1_main.c
 * Author: axel
 *
 * Created on July 5, 2017, 6:42 PM
 */
#include "app_def.h"

#ifdef Home8

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
//#include "mcc.h"
#include "button_input_isr.h"
#include "system.h"
#include "mcc_generated_files/mcc.h"
#include "uart_isr.h"
#include "timeStemp.h"
#include "app_h8_kg_mapIO.h"


void old_main(void)
{
    char Uart_Input=0;
    char Uart_New=0;
    char Data_Input=0;
    char Data_Out=0;
    char Data_Out_old=0;
    char Data_Out_compare=0;
    char Data_Input_compare=0;
    char Data_Input_old=0;

    char UART_Input_compare=0;
    char UART_Input_old=0;
    
    char Data_Blocked=0;
    char Data_Forced=0;
    
    // Configure the oscillator for the device 
    SYSTEM_Initialize();

    //ConfigureOscillator();
    // Initialize I/O and Peripherals for application 
    InitApp();

    INTERRUPT_Initialize();
    OSCILLATOR_Initialize();
    TMR2_Initialize();
    TMR0_Initialize();
    EUSART2_Initialize();
            
    // TODO <INSERT USER APPLICATION CODE HERE> 
    INTCONbits.PEIE = 1;
    PIE1bits.TMR2IE = 1;
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    

    TMR2_SetInterruptHandler(button_input_isr);
    TMR0_SetInterruptHandler(combineIO_KG_Timer);
    //EUSART2_R_InterruptHandler(uart_receiv_isr);
        
    LATEbits.LATE1=1;
    //setLED1(1);
    //setLED2(1);
    

    
    NOP();
    
            
            
    while(1)
    {
        
        //Data_Input=getDataIn();
        
        INTERRUPT_GlobalInterruptDisable();
        NOP();
        NOP();
        Data_Input=array2char(outBufferGlobal);
        Uart_Input=array2char(netBufferGlobal);
        Uart_New  =array2char(netBufferGlobal_new);
        INTERRUPT_GlobalInterruptEnable();
        
        Data_Out_compare = Data_Out ^ Data_Out_old;
        Data_Input_compare=Data_Input ^ Data_Input_old;
        UART_Input_compare=Uart_Input ^ UART_Input_old;
        
        
        Data_Out=combineIO_KG_TEST( Uart_Input, Uart_New, Data_Input, Data_Input_compare, Data_Blocked, Data_Forced);
        pushOutput(Data_Out,Data_Out_old);
        
        Data_Out_old=Data_Out;
        Data_Input_old=Data_Input;
        Uart_Input = UART_Input_old;
        


        
        WNOP();
    }

}



#endif