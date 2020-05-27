/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F16Q41
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.35	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set VDD_REF aliases
#define VDD_REF_TRIS                 TRISAbits.TRISA5
#define VDD_REF_LAT                  LATAbits.LATA5
#define VDD_REF_PORT                 PORTAbits.RA5
#define VDD_REF_WPU                  WPUAbits.WPUA5
#define VDD_REF_OD                   ODCONAbits.ODCA5
#define VDD_REF_ANS                  ANSELAbits.ANSELA5
#define VDD_REF_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VDD_REF_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VDD_REF_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VDD_REF_GetValue()           PORTAbits.RA5
#define VDD_REF_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VDD_REF_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VDD_REF_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VDD_REF_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VDD_REF_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VDD_REF_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VDD_REF_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define VDD_REF_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set HUMID aliases
#define HUMID_TRIS                 TRISBbits.TRISB6
#define HUMID_LAT                  LATBbits.LATB6
#define HUMID_PORT                 PORTBbits.RB6
#define HUMID_WPU                  WPUBbits.WPUB6
#define HUMID_OD                   ODCONBbits.ODCB6
#define HUMID_ANS                  ANSELBbits.ANSELB6
#define HUMID_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define HUMID_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define HUMID_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define HUMID_GetValue()           PORTBbits.RB6
#define HUMID_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define HUMID_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define HUMID_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define HUMID_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define HUMID_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define HUMID_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define HUMID_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define HUMID_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISCbits.TRISC4
#define SW1_LAT                  LATCbits.LATC4
#define SW1_PORT                 PORTCbits.RC4
#define SW1_WPU                  WPUCbits.WPUC4
#define SW1_OD                   ODCONCbits.ODCC4
#define SW1_ANS                  ANSELCbits.ANSELC4
#define SW1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SW1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SW1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SW1_GetValue()           PORTCbits.RC4
#define SW1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SW1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set PRESS aliases
#define PRESS_TRIS                 TRISCbits.TRISC5
#define PRESS_LAT                  LATCbits.LATC5
#define PRESS_PORT                 PORTCbits.RC5
#define PRESS_WPU                  WPUCbits.WPUC5
#define PRESS_OD                   ODCONCbits.ODCC5
#define PRESS_ANS                  ANSELCbits.ANSELC5
#define PRESS_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define PRESS_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define PRESS_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define PRESS_GetValue()           PORTCbits.RC5
#define PRESS_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define PRESS_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define PRESS_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define PRESS_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define PRESS_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define PRESS_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define PRESS_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define PRESS_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/