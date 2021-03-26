/**
  TMR4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr4.c
 
  @Summary
    This is the generated driver implementation file for the TMR4 driver
 
  @Description
    This source file provides APIs for driver for TMR4.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr4.h"

const struct TMR_INTERFACE Timer4 = {
    .Initialize = Timer4_Initialize,
    .Start = Timer4_Start,
    .Stop = Timer4_Stop,
    .PeriodCountSet = Timer4_PeriodCountSet,
    .TimeoutCallbackRegister = Timer4_OverflowCallbackRegister,
    .Tasks = Timer4_Tasks
};

static void (*Timer4_OverflowCallback)(void);
static void Timer4_DefaultOverflowCallback(void);

/**
  Section: TMR4 APIs
*/

void Timer4_Initialize(void){

    // Set TMR4 to the options selected in the User Interface
    // TCS LFINTOSC; 
    T4CLKCON = 0x4;
    // TMODE Software control; TCKSYNC Not Synchronized; TCKPOL Rising Edge; TPSYNC Not Synchronized; 
    T4HLT = 0x0;
    // TRSEL T4INPPS pin; 
    T4RST = 0x0;
    // PR 242; 
    T4PR = 0xF2;
    // TMR 0x0; 
    T4TMR = 0x0;

    // Set Default Interrupt Handler
    Timer4_OverflowCallbackRegister(Timer4_DefaultOverflowCallback);

    // Clearing IF flag.
     PIR10bits.TMR4IF = 0;
    // TCKPS 1:128; TMRON off; TOUTPS 1:10; 
    T4CON = 0x79;
}

void Timer4_ModeSet(Timer4_HLT_MODE mode)
{
   // Configure different types HLT mode
    T4HLTbits.T4MODE = mode;
}

void Timer4_ExtResetSourceSet(Timer4_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T4RSTbits.T4RSEL = reset;
}

void Timer4_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 1;
}

void Timer4_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 0;
}

uint8_t Timer4_Read(void)
{
    uint8_t readVal;
    readVal = TMR4;
    return readVal;
}

void Timer4_Write(uint8_t timerVal)
{
    // Write to the Timer4 register
    TMR4 = timerVal;;
}

void Timer4_PeriodCountSet(size_t periodVal)
{
   PR4 = (uint8_t) periodVal;
}

void Timer4_OverflowCallbackRegister(void (* InterruptHandler)(void)){
    Timer4_OverflowCallback = InterruptHandler;
}

static void Timer4_DefaultOverflowCallback(void){
    // add your TMR4 interrupt custom code
    // or set custom function using Timer4_OverflowCallbackRegister()
}

void Timer4_Tasks(void)
{
    if(PIR10bits.TMR4IF)
    {
        // Clearing IF flag.
        PIR10bits.TMR4IF = 0;
        Timer4_OverflowCallback();
    }
}

/**
  End of File
*/