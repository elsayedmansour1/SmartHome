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
#include "../HAL/LM35/LM35_Interface.h"
#include "util/delay.h"

void ADC_InterruptFunction(void);
extern u8 Flag;
extern u16 LM35_Value;
extern u16 LDR_Value;
int main(void)
{

	u16 LDR_Result=0;
	u16 LM35_Result=0;
	/*LCD initialization*/
	LCD_VidInit();
	/*ADC initialization*/
	/*ADC_VidINIT();
	ADC_Select_Channal(2);
	ADC_Start_Conversion();*/
	LDR_u8Init(PIN1,ADC_InterruptFunction);
	LM35_u8Init(PIN2,ADC_InterruptFunction);
	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);
	LCD_4Bits_VoidClearDisplay();
	while(1)
	{
		/*ADC_Get_Result(&LDR_Result);
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("LDR Value =");
		LCD_4Bits_VidWriteNumber(LDR_Result);
		_delay_ms(300);
		LCD_4Bits_VoidClearDisplay();*/
		LDR_Result=LDR_u8Channal(1);
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("brightness =");
		//LCD_4Bits_SetPosition(0,10);
		LCD_4Bits_VidWriteNumber(LDR_Result);
		LM35_Result=LM35_u8Channal(2);
		LCD_4Bits_SetPosition(1,0);
		LCD_4Bits_DisplayString("Temperature =");
		//LCD_4Bits_SetPosition(1,10);
		LCD_4Bits_VidWriteNumber(LM35_Result);
		_delay_ms(500);
		LCD_4Bits_VoidClearDisplay();

	}





	return 0;
}
void ADC_InterruptFunction(void)
{
	if(Flag==1)
	{
		ADC_Get_Result(&LM35_Value);
	}
	if(Flag==2)
	{
		ADC_Get_Result(&LDR_Value);
	}
}
