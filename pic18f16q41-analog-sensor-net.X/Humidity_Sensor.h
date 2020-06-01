/* 
 * File:   Humidity_Sensor.h
 * Author: C16783
 *
 * Created on April 27, 2020, 12:49 PM
 */

#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/mcc.h"
#include <xc.h>

#ifndef HUMIDITY_SENSOR_H
#define	HUMIDITY_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define CAP_POLYTERM2           301.16
#define CAP_POLYTERM1           902.16
#define CAP_POLYTERM0           764.38
#define CAP_ERROR               27
#define HUMID_POLYTERM2         -0.0405
#define HUMID_POLYTERM1         12.915
#define HUMID_POLYTERM0         -929.12
#define HUMID_ERROR             0
#define ADCC_RESOLUTION         4096
#define ADCC_POS_REFERENCE      4.096

    void Humid_Init(void);
    void Humid_SendData(void);

#ifdef	__cplusplus
}
#endif

#endif	/* HUMIDITY_SENSOR_H */

