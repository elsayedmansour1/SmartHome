/*
 * LM35_Progrm.c
 *
 *  Created on: May 27, 2022
 *      Author: elsay
 */


		 /*LIB*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
			/*MCAL*/
#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/DIO/DIO_config.h"
#include "../../MCAL/Global Interrupt/GIE_INT.h"
#include "../../MCAL/ADC/ADC_INT.h"
		/*hardware*/

#include "util/delay.h"
#include "LM35_Interface.h"
u8 Flag=0;
u16 LM35_Value=0;
void LM35_u8Init(u8 Copy_u8DIO_Pin,void(*func)(void))
{
	GIE_Vid_Enable();
	DIO_VidSetPinDirection(DIO_PORTA,Copy_u8DIO_Pin,INPUT);
	ADC_SetCallBack(func);
	ADC_VidINIT();
	ADC_Interrupt_Enable();
}
u16  LM35_u8Channal(u8 Copy_u8Channal)
{
	Flag=1;
	ADC_Select_Channal(Copy_u8Channal);
	ADC_Start_Conversion();
	LM35_Value=LM35_Value/2;

	return LM35_Value;
}

