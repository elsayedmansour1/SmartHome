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
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/TIMER/TIMER1_Define.h"
		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LDR/LDR_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/Servo/Servo_Interface.h"
#include "../HAL/Key_pad/Keypad_Interface.h"
#include "../HAL/DC_Motor/DC_Motor.h"
#include "../HAL/Buzzer/Buzzer.h"
#include "util/delay.h"

void ADC_InterruptFunction(void);
extern u8 Flag;
extern u16 LM35_Value;
extern u16 LDR_Value;
int main(void)
{

	u16 LDR_Result=0;
	u16 LM35_Result=0;
	u8 Keypad_out=0;
	DIO_VidSetPinDirection(DIO_PORTD,PIN5,OUTPUT);
	/*LCD initialization*/
	LCD_VidInit();
	/*Keypad Initialization*/
	KEYPAD_VidInit();
	/*Servo Initialization*/
	Servo_VoidInit();
	/*Buzzer Initialization*/
	Buzzer_VoidInit();
	/*DC Motor Initialization*/
	DC_Motor_VoidInit();
	/*LDR Function */
	LDR_u8Init(PIN1,ADC_InterruptFunction);
	/*LM35 function*/
	LM35_u8Init(PIN2,ADC_InterruptFunction);
	/*the Intro*/
	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);
	LCD_4Bits_VoidClearDisplay();
	while(1)
	{
		Keypad_out=KEYPAD_GET_PressedKey();
		if(Keypad_out!=0)
		{
			if(Keypad_out==1)
			{
				LCD_4Bits_VoidClearDisplay();
				Servo_u8DoorState(open);
				LCD_4Bits_SetPosition(0,0);
				LCD_4Bits_DisplayString("The Door is open>>>>");
				_delay_ms(150);
			}
			else if(Keypad_out==2)
			{
				LCD_4Bits_VoidClearDisplay();
				Servo_u8DoorState(close);
				LCD_4Bits_SetPosition(0,0);
				LCD_4Bits_DisplayString("The Door is Close<<<<<");
				_delay_ms(150);
			}
		}
		Keypad_out=0;

		/*the functional of LDR function*/
		LDR_Result=LDR_u8Channal(1);
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("Brightness =");
		LCD_4Bits_VidWriteNumber(LDR_Result);
		/*the functional of LM35 function*/
		LM35_Result=LM35_u8Channal(2);
		LCD_4Bits_SetPosition(1,0);
		LCD_4Bits_DisplayString("Temperature =");
		LCD_4Bits_VidWriteNumber(LM35_Result);
		if(LM35_Result>35)
		{
			DC_Motor_On_Off(ON);


		}
	     if(LM35_Result>40)
		{
			Buzzer_On_Off(ON);
		}
		if(LM35_Result<35)
		{
			DC_Motor_On_Off(OFF);
			Buzzer_On_Off(OFF);
		}
		/*Waiting for 500 ms*/
		_delay_ms(500);
		/*clear Display*/
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
