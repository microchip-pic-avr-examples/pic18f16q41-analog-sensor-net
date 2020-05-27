/*
 * File:   Temp_Sensor.c
 * Author: C16783
 *
 * Created on April 16, 2020, 12:03 PM
 */

#include "Temp_Sensor.h"

void Temp_ADCC_Init(void) {
    // Temp Indicator ADCC Sensor Settings
    ADCON1 = 0x00;
    ADCON2 = 0x00;
    ADCON3 = 0x00;
    ADREF = 0x00; // ADCC Negative Ref = VSS; ADCC Positive Ref = VDD
    ADACT = 0x00; // ADCC Auto-Conversion Trigger;
    ADCLK = 0x00; // ADCC Clock Divider Register;
    ADPCH = 0x8D; // ADCC Positive Channel = OPA1OUT; PCH = OPAIN0+(RB5)
    ADCON0 = 0x84; // ADCC Enabled; FOSC/ADCLK; Results Right Justified;
    PIR1bits.ADIF = 0; // Clear ADIF;
    PIE1bits.ADIE = 1; // Enable ADCC Interrupts;
}

void Temp_OPA_Init(void) {
    // MQ135 OPA Sensor Settings
    OPA1CON1 = 0x3F; // RESON Enabled; NSS = VSS; GSEL = 8R / 8R (Gain = 2)
    OPA1CON2 = 0x12; // NCH = Internal Resistor Ladder; PCH = OPA1INx+
    OPA1CON3 = 0x80; // FMS = OPAxOUT; PSS = ADC1PCH (See ADPCH Register)
    OPA1HWC = 0x00; // Hardware Controlled Override Disabled;
    OPA1ORS = 0x00;
    OPA1CON0 = 0x80; // OPA Enabled; User-defined Feedback;
}

void Temp_Init(void) {
    Temp_ADCC_Init();
    Temp_OPA_Init();
}

void Temp_SendData(void) {
    float TempK, TempC, Temp_Voltage = 0;
    float RT = 0; // Voltage Divider R2 (Thermistor)
    float R0 = 10000.0; // Voltage Divider R1;
    float T0 = 298.15;
    adc_result_t Temp_Raw = 0;

    ADCON0bits.GO = 1; // Trigger 1st ADC Conversion;
    while (!ADCON0bits.GO); // Wait for Conversion to Complete;
    Temp_Raw = ADCC_GetConversionResult(); // Get ADC conversion result;

    Temp_Voltage = ((float) Temp_Raw / ADCC_RESOLUTION) * ADCC_VDD_REFERENCE; // Calculate ADC Voltage;
    RT = ((Temp_Voltage / 2) * R0); // Determine Thermistor Resistance (Voltage Divider with Known R1);
    RT = (RT) / (TEMP_POS_REF - (Temp_Voltage / 2)); // Determine Thermistor Resistance (Voltage Divider with Known R1);

    // Determine Temperature from Resistance using Steinhart-Hart model 
    TempK = log(RT / R0);
    TempK = TempK * (1 / TEMP_BETA);
    TempK = TempK + (1 / T0);
    TempK = 1 / TempK;
    TempC = TempK - K_CONST;

    printf("Temperature(C), %1.1f \r\n", TempC);
}