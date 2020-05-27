/* 
 * File:   Pressure_Sensor.h
 * Author: C16783
 *
 * Created on April 27, 2020, 4:24 PM
 */

#ifndef PRESSURE_SENSOR_H
#define	PRESSURE_SENSOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define PRESSURE_CONSTANT       0.057
#define PRESSURE_VSUPPLY        4.75
#define PRESSURE_ERROR          1.5
#define ADCC_RESOLUTION         4096
#define ADCC_POS_REFERENCE      4.096

    void Press_Init(void);
    void Press_SendData(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PRESSURE_SENSOR_H */

