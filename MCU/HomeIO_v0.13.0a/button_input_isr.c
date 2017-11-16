/*
 * File:   button_input_isr.c
 * Author: axel
 *
 * Created on 23. Juni 2017, 20:45
 */


#if defined(__XC)
    //#include <xc.h>         /* XC8 General Include File */
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
#include "hadware_interface.h"
#include "board_def.h"
#include "board_interface.h"

#endif



#define IN_PulsePerCycle 125          // x Interupts für 50 Hz
#define IN_PulseForAktiv 70           // x Interupts für 50 Hz
#define IN_Toggle 1                   // 1 Toogle 0 Ausgang=Eingang
#define IN_CyclesForAktiv 1           // x Halbwellen bis Eingang 1
#define IN_CyclesForDown 1            // x Halbwellen bis Eingang 0



char IN_PulsCounter=0;
char _channel_pulses[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };


char IN_ChanelCyclesCounterUp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
char IN_ChanelCyclesCounterDown[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };


char IN_ChanelAktivated[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
char IN_ChanelOutputBuffer[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };


void button_input_isr()
{
        IN_PulsCounter++;

        if(IN_PulsCounter < IN_PulsePerCycle)
        {
            _channel_pulses[0] = _channel_pulses[0] + getInputPin(0);
            _channel_pulses[1] = _channel_pulses[1] + getInputPin(1);
            _channel_pulses[2] = _channel_pulses[2] + getInputPin(2);
            _channel_pulses[3] = _channel_pulses[3] + getInputPin(3);
            _channel_pulses[4] = _channel_pulses[4] + getInputPin(4);
            _channel_pulses[5] = _channel_pulses[5] + getInputPin(5);
            _channel_pulses[6] = _channel_pulses[6] + getInputPin(6);
            _channel_pulses[7] = _channel_pulses[7] + getInputPin(7);
        }
        if (IN_PulsCounter == IN_PulsePerCycle)
        {
            for(int x=7; x>=0; x--)
            {   
                if(_channel_pulses[x]<IN_PulseForAktiv)
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
                            }
                            else
                            {
                                IN_ChanelOutputBuffer[x]=1;
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
                            }
                        }
                    }
                }
            }
        }
        if (IN_PulsCounter >= IN_PulsePerCycle)
        {

            IN_PulsCounter=0;
            _channel_pulses[0]=0;
            _channel_pulses[1]=0;
            _channel_pulses[2]=0;
            _channel_pulses[3]=0;
            _channel_pulses[4]=0;
            _channel_pulses[5]=0;
            _channel_pulses[6]=0;
            _channel_pulses[7]=0;
        
        


        
       outBufferGlobal[7]=IN_ChanelOutputBuffer[7];
       outBufferGlobal[6]=IN_ChanelOutputBuffer[6];
       outBufferGlobal[5]=IN_ChanelOutputBuffer[5];
       outBufferGlobal[4]=IN_ChanelOutputBuffer[4];
       outBufferGlobal[3]=IN_ChanelOutputBuffer[3];
       outBufferGlobal[2]=IN_ChanelOutputBuffer[2];
       outBufferGlobal[1]=IN_ChanelOutputBuffer[1];
       outBufferGlobal[0]=IN_ChanelOutputBuffer[0];
        }
       
       
}
