#include "mcc.h"

void LedColorCycle(void)
{
    LATEbits.LE1=0;
    //;
    static int count1=0;
    static int count2=0;
    static int count3=0;
    static int count4=0;
    static int count=0;
    
    
    
    


        EPWM1_LoadDutyValue(count1);

        EPWM2_LoadDutyValue(count2);

        EPWM3_LoadDutyValue(0);

        PWM4_LoadDutyValue(count3);
    
    
    

    
        count++;
    
        if(count>=0&&count<1000){
            
            count3=1000;
            count2=0;
            count1++;
        }
        else if(count>=1000&&count<2000){
            count3--;
            count2=0;
            count1=1000;
            
        }
        else if(count>=2000&&count<3000){
            count3=0;
            count2++;
            count1=1000;
            
        }
        else if(count>=3000&&count<4000){
            count3=0;
            count2=1000;
            count1--;
            
        }
        else if(count>=4000&&count<5000){
            count3++;
            count2=1000;
            count1=0;
            
        }
        else if(count>=5000&&count<6000){
            count3=1000;
            count2--;
            count1=0;
            
        }
        else
            count=0;

}


void LedWhiteFade(void)
{
    LATEbits.LE1=1;
        //;
    static int count1=0;
    static int count2=0;
    static int count3=0;
    static int count4=0;
    static int count=0;
    
    
    
    


        EPWM1_LoadDutyValue(count1);

        EPWM2_LoadDutyValue(count2);

        EPWM3_LoadDutyValue(count4);

        PWM4_LoadDutyValue(count3);
    
    
    

    
        count++;
    
        if(count==0)
        {
            count4=0;
            TXREG2='A';
            
        }
        else if(count>0&&count<1000){
            count4++;
        }
        else if(count==1000)
        {
            count4=1000;
        }
        else if(count>1000&&count<2000)
        {
            count4--;
        }
        else
            count=0;
}