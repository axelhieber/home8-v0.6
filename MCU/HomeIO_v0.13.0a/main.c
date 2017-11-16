/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/*
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
#include "Z_app_def.h"
#include "board_def.h"
#include "system.h"        // System funct/params, like osc/peripheral config 
#include "user.h"          // User funct/params, such as InitApp 
#include "hadwareProfile.h"
#include "mapIO.h"
#include "data_types.h"
#include "externvar.h"
#include "hadware_interface.h"
#include "board_interface.h"
#include "mcc.h"
*/

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
/*
void main(void)
{
    // Configure the oscillator for the device 
    SYSTEM_Initialize();

    // Initialize I/O and Peripherals for application 
    InitApp();

    // TODO <INSERT USER APPLICATION CODE HERE> 
    

        
    //etLED1(1);
    //setLED2(1);
    

    
    NOP();
    
            
            
    while(1)
    {
        
        //Data_Input=getDataIn();
        //Data_Input=array2char(outBufferGlobal);
        //Data_Out_old=Data_Out;
        //Data_Out=combineIO(Data_Uart, Data_Input, Data_Blocked, Data_Forced);
        //pushOutput(Data_Out,Data_Out_old);
       

        
        WNOP();
    }

}

*/