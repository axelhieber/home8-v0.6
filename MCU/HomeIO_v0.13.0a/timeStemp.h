/* 
 * File:   timeStemp.h
 * Author: axel
 *
 * Created on August 10, 2017, 6:20 PM
 */

#ifndef TIMESTEMP_H
#define	TIMESTEMP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
    void time_isr(void);
    uint32_t getTimeStemp(void);
    void setTimeStemp(uint32_t time);
    void timeInit(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMESTEMP_H */

