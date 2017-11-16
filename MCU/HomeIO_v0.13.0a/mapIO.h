/* 
 * File:   mapIO.h
 * Author: axel
 *
 * Created on 04. Juni 2016, 02:28
 */

#ifndef MAPIO_H
#define	MAPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#ifdef KG
    #define combineIO char combineIO_KG(char UART, char UART_CHANGED, char INPUT,char INPUT_CHANGED ,char BLOCKED, char FORCED)


#endif
#ifdef EG
    #define combineIO(UART,INPUT,BLOCKED,FORCED) combineIO_EG(UART,INPUT,BLOCKED,FORCED)
#endif
#ifdef OG
    #define combineIO(UART,INPUT,BLOCKED,FORCED) combineIO_OG(UART,INPUT,BLOCKED,FORCED)
#endif
#ifdef DG
    #define combineIO(UART,INPUT,BLOCKED,FORCED) combineIO_DG(UART,INPUT,BLOCKED,FORCED)
#endif
#ifdef HEIZIUNG
    #define combineIO(UART,INPUT,BLOCKED,FORCED) combineIO_HEIZUNG(UART,INPUT,BLOCKED,FORCED)
#endif
#ifdef TEST
    #define combineIO(UART,INPUT,BLOCKED,FORCED) combineIO_TEST(UART,INPUT,BLOCKED,FORCED)
#endif
    

 char combineIO_KG      (char UART, char UART_CHANGED, char INPUT,char INPUT_CHANGED ,char BLOCKED, char FORCED);
 char combineIO_HEIZUNG (char UART, char INPUT, char BLOCKED, char FORCED);
 char combineIO_EG      (char UART, char INPUT, char BLOCKED, char FORCED);
 char combineIO_OG      (char UART, char INPUT, char BLOCKED, char FORCED);
 char combineIO_DG      (char UART, char INPUT, char BLOCKED, char FORCED);
 char combineIO_TEST    (char UART, char INPUT, char BLOCKED, char FORCED);
 
char combineIO_KG_TEST(char UART, char UART_NEW, char INPUT,char INPUT_CHANGED ,char BLOCKED, char FORCED);

void combineIO_KG_Timer(void);
void LedBlink(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MAPIO_H */

