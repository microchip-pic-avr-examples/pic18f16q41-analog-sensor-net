/*
 * File:   C0_Sensor.c
 * Author: C16783
 *
 * Created on April 15, 2020, 1:31 PM
 */

#include "MQ7_Sensor.h"

void MQ7_ADCC_Init(void) {
    // MQ7 ADCC Sensor Settings
    ADCON1 = 0x00;
    ADCON2 = 0x00;
    ADCON3 = 0x00;
    ADREF = 0x03; // ADCC Negative Ref = VSS; ADCC Positive Ref = FVR (4.096 V)
    ADACT = 0x00; // ADCC Auto-Conversion Trigger = TMR0;
    ADCLK = 0x00; // ADCC Clock Divider Register;
    ADPCH = 0x8D; // ADCC Positive Channel = OPA1OUT; PCH = OPAIN0+(RB5)
    ADCON0 = 0x94; // ADCC Enabled; ADC Dedicated OSC; Results Right Justified;
    PIR1bits.ADIF = 0; // Clear ADIF;
    PIE1bits.ADIE = 1; // Enable ADCC Interrupts;
}

void MQ7_OPA_Init(void) {
    // MQ7 OPA Sensor Settings
    OPA1CON1 = 0x00; // RESON Disabled;
    OPA1CON2 = 0x02; // NCH = No Connection; PCH = OPA1INx+
    OPA1CON3 = 0x00; // FMS = No Connection; PSS = ADC1PCH (See ADPCH Register)
    OPA1HWC = 0x00; // Hardware Controlled Override Disabled;
    OPA1ORS = 0x00;
    OPA1CON0 = 0x88; // OPA Enabled; Unity Gain Mode;
}

void MQ7_FVR_Init(void) {
    FVRCONbits.ADFVR = 0b11; // FVR Buffer 1 Gain is 4.096V;
    FVRCONbits.CDAFVR = 0b00; // FVR Buffer 2 Gain is off;
    FVRCONbits.EN = 1; // Enable FVR;
}

void MQ7_PreHeat(void) {
    uint8_t i;
    printf("PIC18F16Q41 Sensor Net \r\n");
    printf("Entering CO Sensor Pre-Heat Stage (150 seconds) \r\n");
    PWM1_16BIT_Enable();
    while (!PWM1GIRbits.S1P1IF);
    PWM1_16BIT_Disable();
    for (i = 0; i < 60; i++) {
        __delay_ms(1000);
    }
    printf("Pre-Heat Complete \r\n");
    printf("PIC18F16Q41 Sensor Net \r\n");
}

void MQ7_Init(void) {
    MQ7_OPA_Init();
    MQ7_ADCC_Init();
    MQ7_FVR_Init();
}

void MQ7_SendData(void) {
    double CO_PPM, CO_Voltage;
    adc_result_t CO_Raw = 0;
    const double R1 = 9300.0; // R1 = Load Resistor (Ohm);
    double RS; // RS = Sensor Resistance (Ohm);
    double ratio; // Rs / R1 Ratio;
    double lgPPM; // PPM Conversion Parameter

    ADCON0bits.GO = 1; // Trigger ADC Conversion;
    while (!ADCON0bits.GO); // Wait for Conversion to Complete;
    CO_Raw = ADCC_GetConversionResult();

    CO_Voltage = ((double) CO_Raw / ADCC_RESOLUTION) * ADCC_POS_REFERENCE;

//    RS = R1 * (ADCC_POS_REFERENCE - CO_Voltage) / CO_Voltage;
//    ratio = RS / R1;
//    lgPPM = ((log10(ratio))*(-3.7)) + 0.9948;
//    CO_PPM = pow(10, logPPM);
    printf("CO Level: %d \r\n", CO_PPM);
    
}