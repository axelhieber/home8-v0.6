#include <xc.h>
#include "system.h"
#include "externvar.h"

void outHardwareKueche()
{
    
    if (PORTCbits.RC3!=finalBufferGlobal[4])
    {
        PORTCbits.RC3=finalBufferGlobal[4];
        if(finalBufferGlobal[4]==1)
        {
            TXREG2=19;
            __delay_ms(10);
        }
        else
        {
            TXREG2=18;
            __delay_ms(10);
        }
        
    }
        if (PORTDbits.RD0!=finalBufferGlobal[2])
    {
        PORTDbits.RD0=finalBufferGlobal[2];
        if(finalBufferGlobal[2]==1)
        {
            TXREG2=17;
            __delay_ms(10);
        }
        else
        {
            TXREG2=16;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD1!=finalBufferGlobal[3])
    {
        PORTDbits.RD1=finalBufferGlobal[3];
        if(finalBufferGlobal[3]==1)
        {
            TXREG2=15;
            __delay_ms(10);
        }
        else
        {
            TXREG2=14;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD2!=finalBufferGlobal[1])
    {
        PORTDbits.RD2=finalBufferGlobal[1];
        if(finalBufferGlobal[1]==1)
        {
            TXREG2=13;
            __delay_ms(10);
        }
        else
        {
            TXREG2=12;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD3!=finalBufferGlobal[0])
    {
        PORTDbits.RD3=finalBufferGlobal[0];
        if(finalBufferGlobal[0]==1)
        {
            TXREG2=11;
            __delay_ms(10);
        }
        else
        {
            TXREG2=10;
            __delay_ms(10);
        }
        
    }


////       PORTCbits.RC0=finalBufferGlobal[7];
////       PORTCbits.RC1=finalBufferGlobal[6];
////       PORTCbits.RC2=finalBufferGlobal[5];
//        // finalBufferGlobal[9]=0;
//       if(( finalBufferGlobal[5]+finalBufferGlobal[4])>= 1)
//       {
//           PORTCbits.RC3=1;
//          // finalBufferGlobal[9]=1;
//       }
//       else
//       {
//           PORTCbits.RC3=0;
//        //   finalBufferGlobal[9]=0;
//       }
////       if((finalBufferGlobal[4] >=1) && finalBufferGlobal[9]==0)
////       {
////           PORTCbits.RC3=1;
////           finalBufferGlobal[9]=1;
////           
////       }
////       else
////       {
////           PORTCbits.RC3=0;
////           finalBufferGlobal[9]=0;
////       }
//       PORTDbits.RD0=finalBufferGlobal[2];
//       PORTDbits.RD1=finalBufferGlobal[3];
//       PORTDbits.RD2=finalBufferGlobal[1];
//       PORTDbits.RD3=finalBufferGlobal[0];
//       
//       TXREG2=0b00000000;
//       __delay_ms(10);
}


void outHardwareOG()
{

////       PORTCbits.RC0=finalBufferGlobal[8];
////       PORTCbits.RC1=finalBufferGlobal[8];
////       PORTCbits.RC2=IfinalBufferGlobal[8];
    
    if (PORTCbits.RC3!=finalBufferGlobal[4])
    {
        PORTCbits.RC3=finalBufferGlobal[4];
        if(finalBufferGlobal[4]==1)
        {
            TXREG2=19;
            PORTEbits.RE1=1;
            __delay_ms(10);
            PORTEbits.RE1=0;
        }
        else
        {
            PORTEbits.RE1=1;
            TXREG2=18;
            __delay_ms(10);
            PORTEbits.RE1=0;
        }
        
    }
        if (PORTDbits.RD0!=finalBufferGlobal[3])
    {
        PORTDbits.RD0=finalBufferGlobal[3];
        if(finalBufferGlobal[3]==1)
        {
            TXREG2=17;
            __delay_ms(10);
        }
        else
        {
            TXREG2=16;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD1!=finalBufferGlobal[2])
    {
        PORTDbits.RD1=finalBufferGlobal[2];
        if(finalBufferGlobal[2]==1)
        {
            TXREG2=15;
            __delay_ms(10);
        }
        else
        {
            TXREG2=14;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD2!=finalBufferGlobal[1])
    {
        PORTDbits.RD2=finalBufferGlobal[1];
        if(finalBufferGlobal[1]==1)
        {
            TXREG2=13;
            __delay_ms(10);
        }
        else
        {
            TXREG2=12;
            __delay_ms(10);
        }
        
    }
    if (PORTDbits.RD3!=finalBufferGlobal[0])
    {
        PORTDbits.RD3=finalBufferGlobal[0];
        if(finalBufferGlobal[0]==1)
        {
            TXREG2=11;
            __delay_ms(10);
        }
        else
        {
            TXREG2=10;
            __delay_ms(10);
        }
        
    }

}

void netHardwareOG()
{

    for(int x=0; x<=6;x++)
    {
        if (netBufferGlobal_b[x]!=netBufferGlobal[x])
        {
            netBufferGlobal_b[x]=netBufferGlobal[x];
            netBufferGlobal_c[x]=1;
            finalBufferGlobal[x]=netBufferGlobal[x];
        } 
    }

    for(int x=0; x<=6;x++)
    {
        if (outBufferGlobal_b[x]!=outBufferGlobal[x])
        {
            outBufferGlobal_b[x]=outBufferGlobal[x];
            outBufferGlobal_c[x]=1;
            finalBufferGlobal[x]=outBufferGlobal[x];
        }

    }

}