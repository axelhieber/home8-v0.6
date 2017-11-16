/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef BOARD_DEF_H
#define	BOARD_DEF_H

//#define KG
#include "app_def.h"


#include <xc.h> // include processor files - each processor file is guarded.  

#if defined(KG) || defined(EG) || defined(OG) || defined(DG) || defined(HEIZUNG) || defined(TEST)
    #define INPUT_0_PORT 'B'
    #define INPUT_0_PIN  0
    #define INPUT_1_PORT 'B'
    #define INPUT_1_PIN  1
    #define INPUT_2_PORT 'B'
    #define INPUT_2_PIN  2
    #define INPUT_3_PORT 'B'
    #define INPUT_3_PIN  3
    #define INPUT_4_PORT 'B'
    #define INPUT_4_PIN  4
    #define INPUT_5_PORT 'B'
    #define INPUT_5_PIN  5
    #define INPUT_6_PORT 'B'
    #define INPUT_6_PIN  6
    #define INPUT_7_PORT 'B'
    #define INPUT_7_PIN  7

    #define LED1_PORT 'E'
    #define LED1_PIN 1
    #define LED2_PORT 'E'
    #define LED2_PIN 2
#endif

#if defined(KG) || defined(EG) || defined(OG) || defined(DG) || defined(HEIZUNG) || defined(TEST)
    #define INPUT_0_PORT 'B'
    #define INPUT_0_PIN  0
    #define INPUT_1_PORT 'B'
    #define INPUT_1_PIN  1
    #define INPUT_2_PORT 'B'
    #define INPUT_2_PIN  2
    #define INPUT_3_PORT 'B'
    #define INPUT_3_PIN  3
    #define INPUT_4_PORT 'B'
    #define INPUT_4_PIN  4
    #define INPUT_5_PORT 'B'
    #define INPUT_5_PIN  5
    #define INPUT_6_PORT 'B'
    #define INPUT_6_PIN  6
    #define INPUT_7_PORT 'B'
    #define INPUT_7_PIN  7

    #define LED1_PORT 'E'
    #define LED1_PIN 1
    #define LED2_PORT 'E'
    #define LED2_PIN 2
#endif
#if defined(LED) 
    #define PWM_0_PORT 'Z'
    #define PWM_0_PIN  8
    #define PWM_1_PORT 'z'
    #define PWM_1_PIN  8
    #define PWM_2_PORT 'Z'
    #define PWM_2_PIN  8
    #define PWM_3_PORT 'Z'
    #define PWM_3_PIN  8

    #define LED1_PORT 'E'
    #define LED1_PIN 1
    #define LED2_PORT 'E'
    #define LED2_PIN 2
#endif


#endif	/* BOARD_DEF_H */

