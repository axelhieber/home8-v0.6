/*
 * File:   main_isr.c
 * Author: axel
 *
 * Created on 23. Juni 2017, 20:45
 */
/******************************************************************************/
/*Files to Include                                                            */
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
#include <string.h>
#include "externvar.h"
#include "button_input_isr.h"

#endif

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Variables */






/* High-priority service */

#if defined(__XC) || defined(HI_TECH_C)
void interrupt high_isr(void)
#elif defined (__18CXX)
#pragma code high_isr=0x08
#pragma interrupt high_isr
void high_isr(void)
#else
#error "Invalid compiler selection for implemented ISR routines"
#endif

{

      /* This code stub shows general interrupt handling.  Note that these
      conditional statements are not handled within 3 seperate if blocks.
      Do not use a seperate if block for each interrupt flag to avoid run
      time errors. */

#if 1
   
    if (RC2IE && RC2IF)
    {
        int recive= RCREG2;
        switch(recive)
        {
            case 10: netBufferGlobal[0]=0; break;
            case 11: netBufferGlobal[0]=1; break;
            case 12: netBufferGlobal[1]=0; break;
            case 13: netBufferGlobal[1]=1; break;
            case 14: netBufferGlobal[2]=0; break;
            case 15: netBufferGlobal[2]=1; break;
            case 16: netBufferGlobal[3]=0; break;
            case 17: netBufferGlobal[3]=1; break;
            case 18: netBufferGlobal[4]=0; PORTEbits.RE2=0; break;
            case 19: netBufferGlobal[4]=1; PORTEbits.RE2=1; break;
        }
        RC2IF=0;
    }
    if (TMR2IE && TMR2IF)
    {
        button_input_isr();
        TMR2IF=0;
    }
    

#endif
}

/* Low-priority interrupt routine */
#if defined(__XC) || defined(HI_TECH_C)
void low_priority interrupt low_isr(void)
#elif defined (__18CXX)
#pragma code low_isr=0x18
#pragma interruptlow low_isr
void low_isr(void)
#else
#error "Invalid compiler selection for implemented ISR routines"
#endif
{

      /* This code stub shows general interrupt handling.  Note that these
      conditional statements are not handled within 3 seperate if blocks.
      Do not use a seperate if block for each interrupt flag to avoid run
      time errors. */

#if 0

      /* TODO Add Low Priority interrupt routine code here. */

      /* Determine which flag generated the interrupt */
      if(<Interrupt Flag 1>)
      {
          <Interrupt Flag 1=0>; /* Clear Interrupt Flag 1 */
      }
      else if (<Interrupt Flag 2>)
      {
          <Interrupt Flag 2=0>; /* Clear Interrupt Flag 2 */
      }
      else
      {
          /* Unhandled interrupts */
      }

#endif

}
