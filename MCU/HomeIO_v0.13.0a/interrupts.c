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

#endif

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Variables */



#define IN_PulsePerCycle 125          // x Interupts für 50 Hz
#define IN_PulseForAktiv 70          // x Interupts für 50 Hz
#define IN_Toggle 1                   // 1 Toogle 0 Ausgang=Eingang
#define IN_CyclesForAktiv 1           // x Halbwellen bis Eingang 1
#define IN_CyclesForDown 1            // x Halbwellen bis Eingang 0

char IN_PulsCounter=0;
char _channel_pulses[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

char IN_CyclesCounter=0;
char IN_ChanelCyclesCounterUp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
char IN_ChanelCyclesCounterDown[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };


char IN_ChanelAktivated[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
char IN_ChanelOutputBuffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

char PriSl, PriHw;
char OUT, INP;
char SOUT;
char CA[8];
char CAC;
char DCAN[8];
char DCANC;
char DCAF[8];
char DCAFC;
char TA[8];
char SBuff[10];
char SBuffC;
char OUT4 = 0;


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
        //PORTDbits.RD1=1;
       
       //125 Interupts = 50 Hz
       
      // PORTEbits.RE1=1;
        if(IN_PulsCounter < IN_PulseForAktiv)
        {
           //  PORTDbits.RD1=1;
        //    PORTEbits.RE1=0;
            IN_PulsCounter++;
            _channel_pulses[0] = _channel_pulses[0] + PORTBbits.RB0;
            _channel_pulses[1] = _channel_pulses[1] + PORTBbits.RB1;
            _channel_pulses[2] = _channel_pulses[2] + PORTBbits.RB2;
            _channel_pulses[3] = _channel_pulses[3] + PORTBbits.RB3;
            _channel_pulses[4] = _channel_pulses[4] + PORTBbits.RB4;
            _channel_pulses[5] = _channel_pulses[5] + PORTBbits.RB5;
            _channel_pulses[6] = _channel_pulses[6] + PORTBbits.RB6;
            _channel_pulses[7] = _channel_pulses[7] + PORTBbits.RB7;
        }
        if (IN_PulsCounter < IN_PulsePerCycle && IN_PulsCounter >= IN_PulseForAktiv )
        {
          //  PORTEbits.RE1=1;
            IN_PulsCounter++;
            for(int x=7; x>=0; x--)
           // int x=0;
            {   
                if(_channel_pulses[x]<40)
                {

                    if (IN_ChanelCyclesCounterUp[x]<IN_CyclesForAktiv)
                    {
                        IN_ChanelCyclesCounterUp[x]++;
                    }
                    if (IN_ChanelCyclesCounterUp[x] >= IN_CyclesForAktiv)
                    {
                        if(IN_ChanelAktivated[x]==0)
                        {
                            IN_ChanelAktivated[x]=1;
                            if (IN_Toggle==1)
                            {
                                IN_ChanelOutputBuffer[x]= !(IN_ChanelOutputBuffer[x]);
                              //  PORTDbits.RD1=1;
                            }
                            else
                            {
                                IN_ChanelOutputBuffer[x]=1;
                               // PORTDbits.RD1=1;
                            }
                        }
                    }
                }
                else
                {
                    if (IN_ChanelCyclesCounterDown[x]<IN_CyclesForDown)
                    {
                        IN_ChanelCyclesCounterDown[x]++;
                    }
                    if (IN_ChanelCyclesCounterDown[x] >= IN_CyclesForDown)
                    {
                        if(IN_ChanelAktivated[x]==1)
                        {
                            IN_ChanelAktivated[x]=0;
                            if (IN_Toggle==1)
                            {
                               // Nichts tun
                            }
                            else
                            {
                                IN_ChanelOutputBuffer[x]=0;
                               // PORTDbits.RD0=0;
                            }
                        }
                    }
                }
            }
        }
        if (IN_PulsCounter >= IN_PulsePerCycle)
        {
                     //   PORTEbits.RE1=0;

            IN_PulsCounter=0;
            _channel_pulses[0]=0;
            _channel_pulses[1]=0;
            _channel_pulses[2]=0;
            _channel_pulses[3]=0;
            _channel_pulses[4]=0;
            _channel_pulses[5]=0;
            _channel_pulses[6]=0;
            _channel_pulses[7]=0;
        }
        
       outBufferGlobal[7]=IN_ChanelOutputBuffer[4];
       outBufferGlobal[6]=IN_ChanelOutputBuffer[4];
       outBufferGlobal[5]=IN_ChanelOutputBuffer[5];
       outBufferGlobal[4]=IN_ChanelOutputBuffer[4];
       outBufferGlobal[3]=IN_ChanelOutputBuffer[2];
       outBufferGlobal[2]=IN_ChanelOutputBuffer[3];
       outBufferGlobal[1]=IN_ChanelOutputBuffer[1];
       outBufferGlobal[0]=IN_ChanelOutputBuffer[0];
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
