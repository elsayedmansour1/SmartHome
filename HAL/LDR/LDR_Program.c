/*
 * LDR_Program.c
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
#include "../../MCAL/ADC/ADC_INT.h"
		/*hardware*/
#include "../LCD/LCD_Interface.h"


#include "util/delay.h"
#include "LDR_Interface.h"



void LDR_u8Init(u8 Copy_u8DIO_Pin)
{
	DIO_VidSetPinDirection(DIO_PORTA,Copy_u8DIO_Pin,INPUT);
	ADC_VidINIT();


}
u16 LDR_u8Channal(u8 Copy_u8Channal)
{
	u16 LDR_Value=0;
	ADC_Select_Channal(Copy_u8Channal);
	ADC_Start_Conversion();
	ADC_Get_Result(&LDR_Value);
	LDR_Value=LDR_Value/10;


	return LDR_Value;

}
