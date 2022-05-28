/*
 * DC_Motor.c
 *
 *  Created on: May 28, 2022
 *      Author: elsay
 */
		 /*LIB*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "DC_Motor.h"
void DC_Motor_VoidInit(void)
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN3,OUTPUT);
	DIO_VidSetPinValue(DIO_PORTA,PIN3,LOW);
}
void DC_Motor_On_Off(u8 Copy_DC_State)
{
	if(Copy_DC_State==ON)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN3,HIGH);
	}
	else if(Copy_DC_State==OFF)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN3,LOW);
	}
}
