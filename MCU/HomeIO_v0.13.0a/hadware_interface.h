/* 
 * File:   hadware_interface.h
 * Author: axel
 *
 * Created on 05. Juni 2016, 00:38
 */

#ifndef HADWARE_INTERFACE_H
#define	HADWARE_INTERFACE_H

#ifdef	__cplusplus
extern "C" {
#endif

char readPortPin(char Port, char Pin);
char readPort(char Port);
char readPortNippel(char Port, char LowerUpper);

void setPortPin(char Port, char Pin, char Data);
char setPort(char Port);
char setPortNippel(char Port, char LowerUpper);



void WNOP();
char UART_Receive(char Channel);


#ifdef	__cplusplus
}
#endif

#endif	/* HADWARE_INTERFACE_H */

