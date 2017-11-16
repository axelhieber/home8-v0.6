#include "data_types.h"
#include "externvar.h"
#include <xc.h>
#include "mcc_generated_files/eusart2.h"
#include "uartString.h"


 char combineIO_KG(char UART, char UART_CHANGED, char INPUT,char INPUT_CHANGED ,char BLOCKED, char FORCED)
 {
     static char Uart_Old_Stored;
     static char Input_Old_Stored;
     union bit_byte tUart;
     union bit_byte tInput;
     union bit_byte tUart_Changed;
     union bit_byte tInput_Changed;
     
     union bit_byte tOutput;
     union bit_byte tBlocked;
     union bit_byte tForced;
     union bit_byte tChanged;
     union bit_byte tTimer;
     
         
     tUart.byte=UART;
     tInput.byte=INPUT;
     tUart_Changed.byte=UART_CHANGED;//Uart_Old_Stored^UART;
     tInput_Changed.byte=Input_Old_Stored^INPUT;
     
     tBlocked.byte=BLOCKED;
     tForced.byte=FORCED;
     tTimer.byte=0x00;
     
   
         
//      tChanged.u.bit4==1?changedBufferGlobal[0]=60:1;
//      tChanged.u.bit4==1?changedBufferGlobal[1]=60:1;
//      tChanged.u.bit4==1?changedBufferGlobal[2]=60:1;
//      tChanged.u.bit4==1?changedBufferGlobal[3]=60:1;
      tChanged.u.bit4==1?timerInputBufferGlobal[4]=60*10:1;
      tChanged.u.bit5==1?timerInputBufferGlobal[5]=60*10:1;
//      tChanged.u.bit4==1?changedBufferGlobal[6]=60:1;
//      tChanged.u.bit4==1?changedBufferGlobal[7]=60:1;
      
//     (changedBufferGlobal[0]>0)?tTimer.u.bit0=1:tTimer.u.bit0=0;
//     (changedBufferGlobal[1]>0)?tTimer.u.bit1=1:tTimer.u.bit1=0;
//     (changedBufferGlobal[2]>0)?tTimer.u.bit2=1:tTimer.u.bit2=0;
//     (changedBufferGlobal[3]>0)?tTimer.u.bit3=1:tTimer.u.bit3=0;
     (timerInputBufferGlobal[4]>0)?tTimer.u.bit4=1:tTimer.u.bit4=0;
     (timerInputBufferGlobal[5]>0)?tTimer.u.bit5=1:tTimer.u.bit5=0;
//     (changedBufferGlobal[6]>0)?tTimer.u.bit6=1:tTimer.u.bit6=0;
//     (changedBufferGlobal[7]>0)?tTimer.u.bit7=1:tTimer.u.bit7=0;
     
     
     tOutput.byte=0x00;
     
     tOutput.u.bit0 = 0;                                //
     tOutput.u.bit1 = (tOutput.u.bit1)^(tInput_Changed.u.bit7|tUart_Changed.u.bit7);//tInput.u.bit7|tUart.u.bit7;                    //Terasse
     tOutput.u.bit2 = 0;                                //
     tOutput.u.bit3 = ((tInput.u.bit4 ^ tInput.u.bit5)&(tTimer.u.bit4 | tTimer.u.bit5));//|tUart.u.bit4|tUart.u.bit5 ;   //Stiege Vorzimmer
     tOutput.u.bit4 = tInput.u.bit3;            //Garage
     tOutput.u.bit5 = tInput.u.bit2;                    //Beamer
     tOutput.u.bit6 = tInput.u.bit0;                    //Küche Herd
     tOutput.u.bit7 = tInput.u.bit1;//tInput.u.bit1|tUart.u.bit1;                    //Küche Tisch
     
     
     Uart_Old_Stored=UART_CHANGED;
     Input_Old_Stored=INPUT_CHANGED;

     
    return(tOutput.byte);
 }
 
void combineIO_KG_Timer(void)
{
//     (changedBufferGlobal[0]>0)?changedBufferGlobal[0]--:changedBufferGlobal[0]=0;
//     (changedBufferGlobal[1]>0)?changedBufferGlobal[1]--:changedBufferGlobal[1]=0;
//     (changedBufferGlobal[2]>0)?changedBufferGlobal[2]--:changedBufferGlobal[2]=0;
//     (changedBufferGlobal[3]>0)?changedBufferGlobal[3]--:changedBufferGlobal[3]=0;
     (timerInputBufferGlobal[4]>0)?timerInputBufferGlobal[4]--:timerInputBufferGlobal[4]=0;
     (timerInputBufferGlobal[5]>0)?timerInputBufferGlobal[5]--:timerInputBufferGlobal[5]=0;
//     (changedBufferGlobal[6]>0)?changedBufferGlobal[6]--:changedBufferGlobal[6]=0;
//     (changedBufferGlobal[7]>0)?changedBufferGlobal[7]--:changedBufferGlobal[7]=0;
     
     (timerUartBufferGlobal[4]>0)?timerUartBufferGlobal[4]--:timerUartBufferGlobal[4]=0;
}

 char combineIO_EG(char UART, char INPUT, char BLOCKED, char FORCED)
 {
     return 0;
 }

 char combineIO_DG(char UART, char INPUT, char BLOCKED, char FORCED)
 {
     return 0;
 }

 char combineIO_OG(char UART, char INPUT, char BLOCKED, char FORCED)
 {
     return 0;
 }

 char combineIO_Heizung(char UART, char INPUT, char BLOCKED, char FORCED)
 {
     return 0;
 }
 
 char combineIO_TEST(char UART, char INPUT, char BLOCKED, char FORCED)
 {


    static char INPUT_OLD =0;
    static char out=0;
    static char count=0;
    
    if(INPUT!=INPUT_OLD)
    {
        if     (count==0)
        {
            out=0b00000001;

        }
        else if(count==1)
        {
            out=0b00000010;

        }
        else if(count==2)
        {
            out=0b00000100;
        }
        else if(count==3)
        {
            out=0b00001000;
        }
        else if(count==4)
        {
            out=0b00010000;
        }
        else if(count==5)
        {
            out=0b00100000;
        }
        else if(count==6)
        {
            out=0b01000000;
        }
        else if(count==7)
        {
            out=0b10000000;
        }
        else //if(count<0||count>7)
        {
            count = -1;
        }
        count++;

    }
         
    INPUT_OLD=INPUT;
    return out;
                 
 }
 
 char combineIO_KG_TEST(char UART, char UART_NEW, char INPUT,char INPUT_CHANGED ,char BLOCKED, char FORCED)
 {
     static char Uart_Old_Stored;
     static char Input_Old_Stored;
     
     union bit_byte tUart;
     union bit_byte tInput;
     union bit_byte tUart_New;
     union bit_byte tUart_Changed;
     union bit_byte tInput_Changed;
     
     static union bit_byte tOutput;

     union bit_byte tChanged;
     union bit_byte tTimerInput;
      union bit_byte tTimerUart;
     
         
     tUart.byte=UART;
     tInput.byte=INPUT;
     tChanged.byte=INPUT_CHANGED;
     tUart_New.byte=UART_NEW;
     
     tUart_Changed.byte=Uart_Old_Stored^UART;
     tInput_Changed.byte=Input_Old_Stored^INPUT;
     

     tTimerInput.byte=0x00;
     
   
         

      tChanged.u.bit4==1?timerInputBufferGlobal[4]=60*5:1;
      tChanged.u.bit5==1?timerInputBufferGlobal[5]=60*5:1;
      
     tUart_New.u.bit4==1?timerUartBufferGlobal[4]=60*5:1;
      
      

     (timerInputBufferGlobal[4]>0)?tTimerInput.u.bit4=1:tTimerInput.u.bit4=0;
     (timerInputBufferGlobal[5]>0)?tTimerInput.u.bit5=1:tTimerInput.u.bit5=0;
     
     (timerUartBufferGlobal[4]>0)?tTimerUart.u.bit4=1:tTimerUart.u.bit4=0;

     
     
     //tOutput.byte=0x00;
     
     tOutput.u.bit0 = 0;                                //
     tOutput.u.bit2 = 0;                                //

//GANG
    if ((tChanged.u.bit4|tChanged.u.bit5)&(tOutput.u.bit3==0) || tUart_New.u.bit4&tUart.u.bit4)
    {
         tOutput.u.bit3 =1;
         putUartStrings("!TER~41_",sizeof("!TER~41_"));   
     }
    else if((tChanged.u.bit4|tChanged.u.bit5)&(tOutput.u.bit3==1) || tUart_New.u.bit4&(!tUart.u.bit4))
     {
         tOutput.u.bit3 =0;
         putUartStrings("!TER~40_",sizeof("!TER~40_"));   
     }
    if((tTimerInput.u.bit4==0&&tTimerInput.u.bit5==0&&tTimerUart.u.bit4==0)&&tOutput.u.bit3==1)
    {
        tOutput.u.bit3=0;
        putUartStrings("!TER~40_",sizeof("!TER~40_"));
    }
     
//Terasse
     if( tChanged.u.bit7&(tOutput.u.bit1==0) || tUart_New.u.bit7&tUart.u.bit7)
     {
         tOutput.u.bit1 = 1;
         putUartStrings("!TER~71_",sizeof("!TER~71_"));
     }
     else if(tChanged.u.bit7&(tOutput.u.bit1==1) || tUart_New.u.bit7&(!tUart.u.bit7))
     {
         tOutput.u.bit1 =0;
         putUartStrings("!TER~70_",sizeof("!TER~70_"));
     }
     
//GARAGE
     if( tChanged.u.bit3&(tOutput.u.bit4==0) || tUart_New.u.bit3&tUart.u.bit3)
     {
         tOutput.u.bit4 = 1;
         putUartStrings("!TER~31_",sizeof("!TER~31_"));
     }
     else if(tChanged.u.bit3&(tOutput.u.bit4==1) || tUart_New.u.bit3&(!tUart.u.bit3))
     {
         tOutput.u.bit4 =0;
         putUartStrings("!TER~30_",sizeof("!TER~30_"));
     }
     
//BEAMER
     if( tChanged.u.bit2&(tOutput.u.bit5==0) || tUart_New.u.bit2&tUart.u.bit2)
     {
         tOutput.u.bit5 = 1;
         putUartStrings("!TER~21_",sizeof("!TER~21_"));
     }
     else if(tChanged.u.bit2&(tOutput.u.bit5==1) || tUart_New.u.bit2&(!tUart.u.bit2))
     {
         tOutput.u.bit5 =0;
         putUartStrings("!TER~20_",sizeof("!TER~20_"));
     }
     
//KÜCHE HERD
     if( tChanged.u.bit0&(tOutput.u.bit6==0) || tUart_New.u.bit0&tUart.u.bit0)
     {
         tOutput.u.bit6 = 1;
         putUartStrings("!TER~01_",sizeof("!TER~01_"));
     }
     else if(tChanged.u.bit0&(tOutput.u.bit6==1) || tUart_New.u.bit0&(!tUart.u.bit0))
     {
         tOutput.u.bit6 =0;
         putUartStrings("!TER~00_",sizeof("!TER~00_"));
     }
     
//KÜCHE TISCH
    if( tChanged.u.bit1&(tOutput.u.bit7==0) || tUart_New.u.bit1&tUart.u.bit1)
     {
         tOutput.u.bit7 =1;
         putUartStrings("!TER~11_",sizeof("!TER~11_"));   
     }
     else if(tChanged.u.bit1&(tOutput.u.bit7==1) || tUart_New.u.bit1&(!tUart.u.bit1))
     {
         tOutput.u.bit7 =0;
         putUartStrings("!TER~10_",sizeof("!TER~10_"));   
     }
          

    //EUSART2_Write(tOutput.byte);
     
     
     if (tUart_New.u.bit0==1)
         netBufferGlobal_new[0]=0;
     if (tUart_New.u.bit1==1)
         netBufferGlobal_new[1]=0;
     if (tUart_New.u.bit2==1)
         netBufferGlobal_new[2]=0;
     if (tUart_New.u.bit3==1)
         netBufferGlobal_new[3]=0;
     if (tUart_New.u.bit4==1)
         netBufferGlobal_new[4]=0;
     if (tUart_New.u.bit5==1)
         netBufferGlobal_new[5]=0;
     if (tUart_New.u.bit6==1)
         netBufferGlobal_new[6]=0;
     if (tUart_New.u.bit7==1)
         netBufferGlobal_new[7]=0;
     
           
//      tUart_New.u.bit0==1?netBufferGlobal_new[0]=0:1;
//      tUart_New.u.bit1==1?netBufferGlobal_new[1]=0:1;
//      tUart_New.u.bit2==1?netBufferGlobal_new[2]=0:1;
//      tUart_New.u.bit3==1?netBufferGlobal_new[3]=0:1;
//      tUart_New.u.bit7==1?netBufferGlobal_new[7]=0:1;

     
     
     Uart_Old_Stored=UART;
     Input_Old_Stored=INPUT;

     
    return(tOutput.byte);
 }
 


        