/*
 * Buzzer.c
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
#include "Buzzer.h"
void Buzzer_VoidInit(void)
{
	DIO_VidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
	DIO_VidSetPinValue(DIO_PORTA,PIN0,LOW);
}
void Buzzer_On_Off(u8 Copy_Buzzer_State)
{
	if(Copy_Buzzer_State==ON)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN0,HIGH);
	}
	else if(Copy_Buzzer_State==OFF)
	{
		DIO_VidSetPinValue(DIO_PORTA,PIN0,LOW);
	}
}
