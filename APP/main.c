/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: elsay
 */

		 /*LIB*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
		/*MCAL*/
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/ADC/ADC_INT.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"

#include "util/delay.h"


int main(void)
{

	u16 LDR_Result=0;
	/*LCD initialization*/
	LCD_VidInit();
	/*ADC initialization*/
	/*ADC_VidINIT();
	ADC_Select_Channal(1);
	ADC_Start_Conversion();*/
	LDR_u8Init(PIN1);
	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);
	LCD_4Bits_VoidClearDisplay();
	while(1)
	{
	/*	ADC_Get_Result(&ADC_Result);
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("LDR Value =");
		LCD_4Bits_VidWriteNumber(ADC_Result);
		_delay_ms(300);
		LCD_VoidClearDisplay();*/
		LDR_Result=LDR_u8Channal(1);
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("brightness =");
		LCD_4Bits_VidWriteNumber(LDR_Result);
		_delay_ms(250);
		LCD_4Bits_VoidClearDisplay();

	}





	return 0;
}
