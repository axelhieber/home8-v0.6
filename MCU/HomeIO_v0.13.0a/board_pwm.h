/* 
 * File:   board_pwm.h
 * Author: axel
 *
 * Created on July 3, 2017, 6:08 PM
 */

#ifndef BOARD_PWM_H
#define	BOARD_PWM_H

#ifdef	__cplusplus
extern "C" {
#endif


    void pwm1Duty();
    void pwm2Duty();
    void pwm3Duty();
    void pwm4Duty();
    void pwm5Duty();
    
    void pwm1Start();
    void pwm2Start();
    void pwm3Start();
    void pwm4Start();
    void pwm5Start();
    
    void pwm1Stop();
    void pwm2Stop();
    void pwm3Stop();
    void pwm4Stop();
    void pwm5Stop();



#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_PWM_H */

