/* 
 * File:   data_types.h
 * Author: axel
 *
 * Created on 05. Juni 2016, 00:14
 */

#ifndef DATA_TYPES_H
#define	DATA_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

union bit_byte
{
  struct
  {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
  }u;
  unsigned char byte;
};

union nipple_byte
{
  struct
  {
    unsigned char nippleLower : 4;
    unsigned char nippleUpper : 4;
  }u;
  unsigned char byte;
};


char array2char(int array[]);
//char char2array(char c);

#ifdef	__cplusplus
}
#endif

#endif	/* DATA_TYPES_H */

