/*
 * File:   data_types.c
 * Author: axel
 *
 * Created on 30. Juni 2017, 20:25
 */


#include <xc.h>
#include "data_types.h"

char array2char(int array[]) {
    union bit_byte b2b;
    
    b2b.u.bit0=array[0]; 
    b2b.u.bit1=array[1];
    b2b.u.bit2=array[2];
    b2b.u.bit3=array[3];
    b2b.u.bit4=array[4];
    b2b.u.bit5=array[5];
    b2b.u.bit6=array[6];
    b2b.u.bit7=array[7];
       
    
    return b2b.byte;
}
