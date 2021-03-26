/* 
 * File:   MQ135_Sensor.h
 * Author: C16783
 *
 * Created on April 16, 2020, 12:04 PM
 */

#ifndef MQ135_SENSOR_H
#define	MQ135_SENSOR_H

#include <xc.h>
#include "mcc_generated_files/system/system.h"
#include <math.h>


#ifdef	__cplusplus
extern "C" {
#endif

#define PPM_CLEAN_AIR           5
#define MQ135_ERROR             -0.7
#define MQ135_TERM1             662.9382
#define MQ135_TERM0             -4.0241
#define ADCC_RESOLUTION         4096
#define ADCC_POS_REFERENCE      4.096

    float R1 = 9500.0; // R1 = Load Resistor (Ohm);
    float R0; // Resistance Value in Clean Air;
    float ratio; // RS / R0 Ratio;

    // Function Declarations;
    void MQ135_Init(void);
    void MQ135_SendData(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MQ135_SENSOR_H */

