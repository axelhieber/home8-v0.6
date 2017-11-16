/* 
 * File:   uart_isr.h
 * Author: axel
 *
 * Created on August 2, 2017, 11:49 PM
 */

#ifndef UART_ISR_H
#define	UART_ISR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
int uart_command_check_without_data(char a[],char b[]);
int uart_command_check_out_data(char a[],char b[]);
void uart_receiv_isr(void);





#ifdef	__cplusplus
}
#endif

#endif	/* UART_ISR_H */

