/*
 * LM35_Interface.h
 *
 *  Created on: May 27, 2022
 *      Author: elsay
 */

#ifndef SMARTHOME_HAL_LM35_LM35_INTERFACE_H_
#define SMARTHOME_HAL_LM35_LM35_INTERFACE_H_

void LM35_u8Init(u8 Copy_u8DIO_Pin,void(*func)(void));
u16  LM35_u8Channal(u8 Copy_u8Channal);

#endif /* SMARTHOME_HAL_LM35_LM35_INTERFACE_H_ */
