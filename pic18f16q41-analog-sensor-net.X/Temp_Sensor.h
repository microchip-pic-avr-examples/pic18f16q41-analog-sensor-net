/* 
 * File:   Temp_Sensor.h
 * Author: C16783
 *
 * Created on April 23, 2020, 2:03 PM
 */

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <math.h>

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ADCC_RESOLUTION         4096
#define ADCC_VDD_REFERENCE      4.70        // Measured VDD;
#define TEMP_POS_REF            3.3         // Thermistor Circuit Positive Reference;
#define TEMP_BETA               3289.66     // Thermistor Beta Coefficiant;
#define K_CONST                 273.15
#define TEMP_ERROR              -2
    
    void Temp_Init(void);
    void Temp_OPA_Init(void);
    void Temp_SendData(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_SENSOR_H */

