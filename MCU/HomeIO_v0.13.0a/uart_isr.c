#include <xc.h>
#include <string.h>
#include "uartString.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "externvar.h"
#include "timeStemp.h"

struct tm t;

#define MAX_LEN 20

void uart_receiv_isr(void)
{
    
        
        //LATEbits.LATE2= !LATEbits.LATE2;


        const char emty_buff[MAX_LEN]={0};
        static char in_buff[MAX_LEN]={0};
        static int len=0;
        static int buff_len=0;
        
        int buff_ended=0;
        int buff=RCREG2;
        
        const char STX='!';
        const char ETX='_';
        const char SEPERATOR='~';
        
        char BEFEHL_SET_WHITE[] ={'S','T','W'};
        char BEFEHL_SET_GREEN[] ={'S','T','G'};
       /* char BEFEHL_SET_BLUE[]='STB';
        char BEFEHL_SET_RED[]   ='STR';
        
        char BEFEHL_SET_PETTERN_0[] ='SP0';  //no Pettern
        char BEFEHL_SET_PETTERN_1[] ='SP1';  //LedColorZycle
        char BEFEHL_SET_PETTERN_2[] ='SP2';  //LedWhiteFade
*/
       /* switch(buff)
        {
            case 'A': TMR6_SetInterruptHandler(LedColorCycle); break;
            case 'B': TMR6_SetInterruptHandler(LedWhiteFade);break;
        }
        * */
        
        if(buff==STX)
        {
            
            //strncmp(in_buff,"\0\0\0\0\0\0\0\0\0\0",MAX_LEN);
            memset(in_buff,0,sizeof(in_buff));
            in_buff[0]=buff;
            len=1;
        }
        else if(buff==ETX)
        {
            in_buff[len]=buff;
            in_buff[len+1]='\0';
            buff_len=len;
            len=0;
            buff_ended=1;
            
        }
        else if(len>=1,len<MAX_LEN)
        {
            in_buff[len]=buff;
            len++;
        }
        else
        {
            memset(in_buff,0,sizeof(in_buff));
            len=0;
            
        }
        //EUSART2_Receive_ISR();
        
        
        if(buff_ended==1)
        {            
            buff_ended=0;
            
            if(0==strncmp("!STR~",in_buff,4))
            {
               // LATEbits.LATE1= !LATEbits.LATE1;
                if(buff_len>=(8-1))
                {
                    
                    

                    //LATEbits.LATE1= !LATEbits.LATE1;
                    if(in_buff[5]>='0'&&in_buff[5]<='7')
                    {
                        
                        if(in_buff[6]=='1'||in_buff[6]=='0')
                        {
                            LATEbits.LATE1= !LATEbits.LATE1;
                            netBufferGlobal[in_buff[5]-'0']=in_buff[6]-'0';
                            netBufferGlobal_new[in_buff[5]-'0']=1;
                        }
                    }
                }
            }
            else if(0==strncmp("!SAR",in_buff,4))
            {
               // TMR6_SetInterruptHandler(LedWhiteFade);
               //LATEbits.LATE2= !(LATEbits.LATE2); 
            }
            
            else if(0==strncmp("!GTR~",in_buff,4))
            {
//                TMR6_SetInterruptHandler(LedNOP);
//                int num = (in_buff[5]-'0')*100+(in_buff[6]-'0')*10+(in_buff[7]-'0')*1;
//                LedSetRGB(-1,-1,-1,num);
            }
            
            else if(0==strncmp("!GAR",in_buff,4))
            {
//                TMR6_SetInterruptHandler(LedNOP);
//                int num = (in_buff[5]-'0')*100+(in_buff[6]-'0')*10+(in_buff[7]-'0')*1;
//                LedSetRGB(num,-1,-1,-1);
            }
            else if(0==strncmp("!STG~",in_buff,4))
            {
//                TMR6_SetInterruptHandler(LedNOP);
//                int num = (in_buff[5]-'0')*100+(in_buff[6]-'0')*10+(in_buff[7]-'0')*1;
//                LedSetRGB(-1,num,-1,-1);;
            }
            else if(0==strncmp("!STB~",in_buff,4))
            {
//                TMR6_SetInterruptHandler(LedNOP);
//                int num = (in_buff[5]-'0')*100+(in_buff[6]-'0')*10+(in_buff[7]-'0')*1;
//                LedSetRGB(-1,-1,num,-1);
            }
            else if(0==strncmp("!STW~",in_buff,4))
            {
//                TMR6_SetInterruptHandler(LedNOP);
//                int num = (in_buff[5]-'0')*100+(in_buff[6]-'0')*10+(in_buff[7]-'0')*1;
//                LedSetRGB(-1,-1,-1,num);
            }
            else if(0==strncmp("!TMR~",in_buff,4))
            {
                char text[40]="";
                    t.tm_sec    = 10;
                    t.tm_min    = 10;
                    t.tm_hour   = 6;
                    t.tm_mday   = 25;
                    t.tm_mon    = 2;
                    t.tm_year   = 117;
                    t.tm_wday   = 6;
                long aa;
                aa=getTimeStemp();
               // strncpy(text,ctime(getTimeStemp()),40);
                //putUartStrings(ctime(1490422210),strlen(ctime(1490422210)));
                sprintf(text," Hie %s axel" ,asctime(localtime(&aa)) );
                //putUartStrings(asctime(&t),strlen(asctime(&t)));
                putUartStrings(text,30);
                //putUartStrings("HALLO!",6);
                //TMR6_SetInterruptHandler(LedNOP);
//                LedSetRGB(0,0,0,0);
            }
            else if(0==strncmp("!TMS~",in_buff,4))
            {
                long number=0;
                char * aa;
                number = strtol(&in_buff[5],aa,10);
                setTimeStemp(number);
            }


        }
        PIR3bits.RC2IF =0;
}

int uart_command_check_without_data(char a[],char b[])
{
    int i=0;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    return 1;
}
int uart_command_check_with_data(char a[],char b[])
{
    int i=0;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    i++;
    if (a[i]!=b[i])
        return 0;
    return 1;
}