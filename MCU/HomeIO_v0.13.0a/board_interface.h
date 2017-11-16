/* 
 * File:   board_interface.h
 * Author: axel
 *
 * Created on 01. Juli 2017, 01:40
 */

#ifndef BOARD_INTERFACE_H
#define	BOARD_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

void pushOutput(char OUT , char change);
char getInputPin(char in);
void setLED(char LED_PORT, char LED_PIN , char value);
void setLED1(char value);
void setLED2(char value);


#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_INTERFACE_H */

