/* 
 * File:   CO_Sensor.h
 * Author: C16783
 *
 * Created on April 15, 2020, 1:32 PM
 */

#ifndef CO_SENSOR_H
#define	CO_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <math.h>

#define ADCC_RESOLUTION         4096
#define ADCC_POS_REFERENCE      4.096

    // Function Declarations;
    void MQ7_PreHeat(void);
    void MQ7_Init(void);
    void MQ7_SendData(void);


#ifdef	__cplusplus
}
#endif

#endif	/* CO_SENSOR_H */

