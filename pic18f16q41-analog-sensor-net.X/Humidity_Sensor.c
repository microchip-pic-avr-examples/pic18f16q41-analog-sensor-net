/*
 * File:   humidity_sensor.c
 * Author: C16783
 *
 * Created on April 27, 2020, 12:47 PM
 */

#include "Humidity_Sensor.h"

void Humid_ADCC_Init(void) {
    // Humidity Sensor ADCC Sensor Settings
    ADCON1 = 0x01; // Double Sampling Enabled;
    ADCON2 = 0x00;
    ADCON3 = 0x00;
    ADPREL = 0x0A; // ADCC Pre-charge Time
    ADACQL = 0x0A; // ADCC Acquisition Time;
    ADCAP = 0x1F; // Additional Sample and Hold = 31pf;
    ADREF = 0x03; // ADCC Negative Ref = VSS; ADCC Positive Ref = FVR (4.096 V)
    ADACT = 0x00; // ADCC Auto-Conversion Trigger = TMR0;
    ADCLK = 0x00; // ADCC Clock Divider Register;
    ADPCH = HUMID; // 
    ADCON0 = 0x84; // ADCC Enabled; Continuous Operation Enabled;; Results Right Justified;
    PIR1bits.ADIF = 0; // Clear ADIF;
    PIE1bits.ADIE = 1; // Enable ADCC Interrupts;
}

void Humid_FVR_Init(void) {
    FVRCONbits.ADFVR = 0b11; // FVR Buffer 1 Gain is 4.096V;
    FVRCONbits.CDAFVR = 0b00; // FVR Buffer 2 Gain is off;
    FVRCONbits.EN = 1; // Enable FVR;
}

void Humid_Init(void) {
    Humid_ADCC_Init();
    Humid_FVR_Init();
}

void Humid_SendData(void) {
    float Humid, Humid_Capacitance, Humid_Voltage = 0;
    adc_result_t Humid_Raw = 0;

    ADCON0bits.GO = 1; // Trigger 1st ADC Conversion;
    while (!ADCON0bits.GO); // Wait for Conversion to Complete;

    Humid_Raw = ADCC_GetConversionResult(); // Get ADC conversion result;
    Humid_Voltage = ((float) Humid_Raw / ADCC_RESOLUTION) * ADCC_POS_REFERENCE;
    Humid_Capacitance = ((CAP_POLYTERM2 * (Humid_Voltage * Humid_Voltage))-(CAP_POLYTERM1 * (Humid_Voltage))+(CAP_POLYTERM0))+(CAP_ERROR);

    Humid = (HUMID_POLYTERM2 * (Humid_Capacitance * Humid_Capacitance));
    Humid = Humid + (HUMID_POLYTERM1 * Humid_Capacitance);
    Humid = Humid + HUMID_POLYTERM0;

//    printf("C, %.2f\r\n", Humid_Capacitance); // Print Capacitance for Error Compensation
    printf("Relative Humidity(%%), %.2f\r\n", Humid);

}