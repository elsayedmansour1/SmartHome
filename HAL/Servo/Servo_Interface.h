/*
 * Servo_Interface.h
 *
 *  Created on: May 27, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_HAL_SERVO_SERVO_INTERFACE_H_
#define SMARTHOME_HAL_SERVO_SERVO_INTERFACE_H_

#define open 1
#define close 0


void Servo_VoidInit(void);
void Servo_u8DoorState(u8 copy_DoorState);

#endif /* SMARTHOME_HAL_SERVO_SERVO_INTERFACE_H_ */
