/**
  TMR4 Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    tmr4.h
 
  @Summary
    This is the generated header file for the TMR4 driver
 
  @Description
    This header file provides APIs for driver for TMR4.
    Generation Information :
        Driver Version    :  3.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLAB X v5.45
*/

/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/

#ifndef TMR4_H
#define TMR4_H

/**
 * @brief This file contains API prototypes and other datatypes for TMR4 module.
 * @defgroup TMR4_driver  TMR4
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"

/**
 Section: Data Type Definitions
*/
/**
 @ingroup TMR4_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for TMR4 module
 */
extern const struct TMR_INTERFACE Timer4;

/**
  HLT Mode Setting Enumeration

  @Summary
    Defines the different modes of the HLT.

  @Description
    This defines the several modes of operation of the Timer with
	HLT extension. The modes can be set in a control register associated
	with the timer
*/

typedef enum
{

	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   Timer4_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   Timer4_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   Timer4_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   Timer4_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   Timer4_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   Timer4_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   Timer4_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   Timer4_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   Timer4_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   Timer4_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   Timer4_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   Timer4_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   Timer4_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   Timer4_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   Timer4_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   Timer4_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   Timer4_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   Timer4_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   Timer4_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   Timer4_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   Timer4_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} Timer4_HLT_MODE;

/**
  HLT Reset Source Enumeration

  @Summary
    Defines the different reset source of the HLT.

  @Description
    This source can control starting and stopping of the
	timer, as well as resetting the timer, depending on
	which mode the timer is in. The mode of the timer is
	controlled by the HLT_MODE
*/

typedef enum
{
     /* T4INPPS is the Timer external reset source
     */
    Timer4_T4INPPS,

    /* Timer2 Postscale is the Timer external reset source 
     */
    Timer4_T2POSTSCALED,
    
    /* Reserved enum cannot be used 
     */
    Timer4_RESERVED,
    
    /* Timer6 Postscale is the Timer external reset source 
     */
    Timer4_T6POSTSCALED,

    /* CCP1_OUT is the Timer external reset source 
     */
    Timer4_CCP1_OUT,

    /* CCP2_OUT is the Timer external reset source 
     */
    Timer4_CCP2_OUT,

    /* CCP3_OUT is the Timer external reset source 
     */
    Timer4_CCP3_OUT,

    /* PWM1S1P1_out is the Timer external reset source 
     */
    Timer4_PWM1S1P1_OUT,

    /* PWM1S1P2_out is the Timer external reset source 
     */
    Timer4_PWM1S1P2_OUT,

    /* PWM2S1P1_out is the Timer external reset source 
     */
    Timer4_PWM2S1P1_OUT,

    /* PWM2S1P2_out is the Timer external reset source 
     */
    Timer4_PWM2S1P2_OUT,

    /* PWM3S1P1_out is the Timer external reset source 
     */
    Timer4_PWM3S1P1_OUT,

    /* PWM3S1P2_out is the Timer external reset source 
     */
    Timer4_PWM3S1P2_OUT,

    /* Reserved enum cannot be used 
    */
    Timer4_RESERVED_2,

    /* Reserved enum cannot be used 
    */
    Timer4_RESERVED_3,

    /* CMP1_OUT is the Timer external reset source 
     */
    Timer4_CMP1_OUT,

    /* CMP2_OUT is the Timer external reset source 
     */
    Timer4_CMP2_OUT,

    /* ZCD_Output is the Timer external reset source 
     */
    Timer4_ZCD_OUTPUT,

    /* CLC1_out is the Timer external reset source 
     */
    Timer4_CLC1_OUT,
         
    /* CLC2_out is the Timer external reset source 
     */
    Timer4_CLC2_OUT,
            
    /* CLC3_out is the Timer external reset source 
     */
    Timer4_CLC3_OUT,

    /* CLC4_out is the Timer external reset source 
     */
    Timer4_CLC4_OUT,  

    /* CLC5_out is the Timer external reset source 
     */
    Timer4_CLC5_OUT,
         
    /* CLC6_out is the Timer external reset source 
     */
    Timer4_CLC6_OUT,
            
    /* CLC7_out is the Timer external reset source 
     */
    Timer4_CLC7_OUT,
    
    /* CLC8_out is the Timer external reset source 
     */
    Timer4_CLC8_OUT,

    /* UART1_rx_edge is the Timer external reset source 
     */
    Timer4_UART1_RX_EDGE,

    /* UART1_tx_edge is the Timer external reset source 
     */
    Timer4_UART1_TX_EDGE,

    /* UART2_rx_edge is the Timer external reset source 
     */
    Timer4_UART2_RX_EDGE,

    /* UART2_tx_edge is the Timer external reset source 
     */
    Timer4_UART2_TX_EDGE,

    /* UART3_rx_edge is the Timer external reset source 
     */
    Timer4_UART3_RX_EDGE,

    /* UART3_tx_edge is the Timer external reset source 
     */
    Timer4_UART3_TX_EDGE,

    /* UART4_rx_edge is the Timer external reset source 
     */
    Timer4_UART4_RX_EDGE,

    /* UART4_tx_edge is the Timer external reset source 
     */
    Timer4_UART4_TX_EDGE,

    /* UART5_rx_edge is the Timer external reset source 
     */
    Timer4_UART5_RX_EDGE,

    /* UART5_tx_edge is the Timer external reset source 
     */
    Timer4_UART5_TX_EDGE,

    /* Reserved enum cannot be used 
    */
    Timer4_RESERVED_4

} Timer4_HLT_EXT_RESET_SOURCE;


/**
  Section: Macro Declarations
*/

/**
  Section: TMR4 APIs
*/

/**
 * @ingroup TMR4_driver
 * @brief This API initializes the TMR4 module.
 *        This routine must be called before any other TMR4 routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer4_Tasks();
 *     }
 * }
 * @endcode
 */
 void Timer4_Initialize(void);

/**
 * @ingroup TMR4_driver
 * @brief Configures the Hardware Limit Timer mode.
 *        Writes the T2HLTbits.MODE bits.
 *        TMR4 should be initialized with Timer4_Initialize after calling this API.
 * @param mode - Value to write into T4HLTbits.MODE bits.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_HLT_MODE hltmode;
 *     hltmode = Timer4_ROP_STARTS_TMRON_EN;
 *
 *     // Initialize TMR4 module
 *     Timer4_Initialize();
 *	   // Set the HLT mode
 *	   Timer4_ModeSet (hltmode);
 *
 *     // Do something else...
 * }
 * @endcode
 */
void Timer4_ModeSet(Timer4_HLT_MODE mode);

/**
 * @ingroup TMR4_driver
 * @brief Configures the HLT external reset source.
 *        Writes the T4RSTbits.RSEL bits.
 *        TMR4 should be initialized with Timer4_Initialize after calling this API.
 * @param reset - Value to write into T4RSTbits.RSEL bits.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_HLT_EXT_RESET_SOURCE hltresetsrc;
 *     hltresetsrc = T4IN;
 *
 *     // Initialize TMR4 module
 *     Timer4_Initialize();
 *
 *	   // Set the HLT mode
 *	   Timer4_ExtResetSourceSet(hltresetsrc);
 *
 *     // Do something else...
 * }
 * @endcode
 */
void Timer4_ExtResetSourceSet(Timer4_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup TMR4_driver
 * @brief This function starts TMR4.
 *        TMR4 should be initialized with Timer4_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer4_Start();
 *     
 *     while(1)
 *     {
 *         Timer4_Start();
 *     }
 * }
 * @endcode
 */
void Timer4_Start(void);

/**
 * @ingroup TMR4_driver
 * @brief This function stops TMR4.
 *        TMR4 should be initialized with Timer4_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void customAppCallback(void)
 * {
 *     static uint8_t counter;
 *     if(counter++ == 10)
 *     {
 *         counter = 0;
 *         //Stop timer after 10 timeouts
 *         Timer4_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     
 *     while(1)
 *     {
 *         Timer4_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer4_Stop(void);

/**
 * @ingroup TMR4_driver
 * @brief This function reads the 8 bits from TMR4 register.
 *        TMR4 should be initialized with Timer4_Initialize() before calling this API.
 * @param void.
 * @return 8-bit data from TMR4 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer4_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer4_Read(); == 0x80)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint8_t Timer4_Read(void);

/**
 * @ingroup TMR4_driver
 * @brief This function writes 8-bit value to TMR4 register.
 *        TMR4 should be initialized with Timer4_Initialize() before calling this API.
 * @param 8-bit value to be written to TMR4 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     
 *     while(1)
 *     {
 *         if(Timer4_Read() == 0x0)
 *         {
 *             Timer4_Write();
 *         }
 *     }
 * }
 * @endcode
 */
void Timer4_Write(uint8_t timerVal);

/**
 * @ingroup TMR4_driver
 * @brief This function loads 8 bit value to PR4H register.
 *        TMR4 should be initialized with Timer4_Initialize() before calling this API.
 * @param 8-bit value to be written to PR4 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize()
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR4
 *             Timer4_PeriodCountSet(0x80);
 *         }
 *     }
 * }
 * @endcode
 */
void Timer4_PeriodCountSet(size_t periodVal);

/**
 * @ingroup TMR4_driver
 * @brief Setter function for TMR4 overflow Callback.
 * @param CallbackHandler - Pointer to custom Callback.
 * @return void
 *
 * @code
 * void customOverflowCallback(void)
 * {
 *    //Custom ISR code
 * }
 *
 * void main(void)
 * {
 *     Timer4_Initialize();
 *     Timer4_OverflowCallbackRegister(customOverflowCallback)
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
void Timer4_OverflowCallbackRegister(void (* InterruptHandler)(void));

/**
 * @ingroup TMR4_driver
 * @brief This function performs tasks to be executed on timer overflow event
 * @param void
 * @return void
 *
 * @code
 * void main(void)
 * {
 *     Timer4_Initialize();
 *
 *     while(1)
 *     {
 *         Timer4_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer4_Tasks(void);

#endif // TMR4_H
/**
 End of File
*/