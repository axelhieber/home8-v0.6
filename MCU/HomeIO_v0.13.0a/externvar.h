/* 
 * File:   externvar.h
 * Author: axel
 *
 * Created on 11. März 2016, 16:29
 */

#ifndef EXTERNVAR_H
#define	EXTERNVAR_H

#ifdef	__cplusplus
extern "C" {
#endif


extern int outBufferGlobal[10];
extern int netBufferGlobal[10];
extern int netBufferGlobal_new[10];
extern int outBufferGlobal_new[10];

extern int timerInputBufferGlobal[10];
extern int timerUartBufferGlobal[10];

/*
extern int inBussBufferGlobal[10];

extern int finalBufferGlobal[10];

extern int outBufferGlobal_b[10];
extern int inBussBufferGlobal_b[10];
extern int netBufferGlobal_b[10];

extern int outBufferGlobal_c[10];
extern int inBussBufferGlobal_c[10];
extern int netBufferGlobal_c[10];
extern int finalBufferGlobal_c[10];
*/

#ifdef	__cplusplus
}
#endif

#endif	/* EXTERNVAR_H */

