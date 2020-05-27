/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F16Q41
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "MQ7_Sensor.h"
#include "MQ135_Sensor.h"
#include "Temp_Sensor.h"
#include "Humidity_Sensor.h"
#include "Pressure_Sensor.h"

/*
                         Main application
 */

enum state {
    SENSOR_NET_SPLASH,
    MQ135_SENSOR,
    HUMIDITY_SENSOR,
    TEMP_SENSOR,
    PRESSURE_SENSOR,
};

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    enum state currentState = SENSOR_NET_SPLASH;
    uint8_t InitFlag = 0;

    while (1) {
        switch (currentState) {
            case SENSOR_NET_SPLASH:
                printf("PIC18F16Q41 Sensor Net Application Note \r\n");
                printf("Press button S1 to cycle through sensor nodes \r\n");
                TMR4_StartTimer();
                while (!PIR10bits.TMR4IF);
                TMR4_StopTimer();
                currentState = MQ135_SENSOR;
                break;

            case MQ135_SENSOR:
                if (InitFlag == 0) {
                    MQ135_Init();
                    InitFlag = 1;
                }
                MQ135_SendData();
                if (SW1_GetValue() == 0) {
                    TMR2_StartTimer();
                    while (!PIR3bits.TMR2IF);
                    if (SW1_GetValue() == 0) {
                        InitFlag = 0;
                        currentState = HUMIDITY_SENSOR;
                    }
                }
                break;

            case HUMIDITY_SENSOR:
                if (InitFlag == 0) {
                    Humid_Init();
                    InitFlag = 1;
                }
                Humid_SendData();
                if (SW1_GetValue() == 0) {
                    TMR2_StartTimer();
                    while (!PIR3bits.TMR2IF);
                    if (SW1_GetValue() == 0) {
                        InitFlag = 0;
                        currentState = TEMP_SENSOR;
                    }
                }
                break;

            case TEMP_SENSOR:
                if (InitFlag == 0) {
                    Temp_Init();
                    InitFlag = 1;
                }
                Temp_SendData();
                if (SW1_GetValue() == 0) {
                    TMR2_StartTimer();
                    while (!PIR3bits.TMR2IF);
                    if (SW1_GetValue() == 0) {
                        InitFlag = 0;
                        currentState = PRESSURE_SENSOR;
                    }
                }
                break;

            case PRESSURE_SENSOR:
                if (InitFlag == 0) {
                    Press_Init();
                    InitFlag = 1;
                }
                Press_SendData();
                if (SW1_GetValue() == 0) {
                    TMR2_StartTimer();
                    while (!PIR3bits.TMR2IF);
                    if (SW1_GetValue() == 0) {
                        InitFlag = 0;
                        currentState = MQ135_SENSOR;
                    }
                }
                break;
        }
    }
}

/**
 End of File
 */