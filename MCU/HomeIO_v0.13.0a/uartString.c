
#include "mcc_generated_files/mcc.h"

 void putUartStrings(char text[],int len)
 {
     for(int i=0; i<(len-1); i++)
     {
         EUSART2_Write(text[i]);
     }
     EUSART2_Write(10); //line feed
 }
