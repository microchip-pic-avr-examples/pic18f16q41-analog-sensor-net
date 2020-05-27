/*
 * File:   Pressure_Sensor.c
 * Author: C16783
 *
 * Created on April 27, 2020, 4:24 PM
 */

#include "Pressure_Sensor.h"
#include "mcc_generated_files/mcc.h"
#include "Temp_Sensor.h"
#include <xc.h>

void Press_ADCC_Init(void) {
    // MQ7 ADCC Sensor Settings
    ADCON1 = 0x00;
    ADCON2 = 0x00;
    ADCON3 = 0x00;
    ADREF = 0x03; // ADCC Negative Ref = VSS; ADCC Positive Ref = FVR (4.096 V)
    ADACT = 0x00; // ADCC Auto-Conversion Trigger = TMR0;
    ADCLK = 0x00; // ADCC Clock Divider Register;
    ADPCH = PRESS; // PCH = PRESS;
    ADCON0 = 0x94; // ADCC Enabled; ADC Dedicated OSC; Results Right Justified;
    PIR1bits.ADIF = 0; // Clear ADIF;
    PIE1bits.ADIE = 1; // Enable ADCC Interrupts;
}

void Press_FVR_Init(void) {
    FVRCONbits.ADFVR = 0b11; // FVR Buffer 1 Gain is 4.096V;
    FVRCONbits.CDAFVR = 0b00; // FVR Buffer 2 Gain is off;
    FVRCONbits.EN = 1; // Enable FVR;
}

void Press_Init(void) {
    Press_ADCC_Init();
    Press_FVR_Init();
}

void Press_SendData(void) {
    float Pressure, Press_Voltage = 0;
    adc_result_t Press_Raw = 0;

    ADCON0bits.GO = 1; // Trigger ADC Conversion;
    while (!ADCON0bits.GO); // Wait for Conversion to Complete;
    Press_Raw = ADCC_GetConversionResult();

    Press_Voltage = ((float) Press_Raw / ADCC_RESOLUTION) * ADCC_POS_REFERENCE;
    Pressure = (((Press_Voltage / PRESSURE_VSUPPLY)-(0.5)) / (PRESSURE_CONSTANT)) + PRESSURE_ERROR;
    printf("Differential Pressure(kPa), %.2f\r\n", Pressure);
}