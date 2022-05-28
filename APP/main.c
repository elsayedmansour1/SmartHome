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
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/ADC/ADC_INT.h"
#include "../MCAL/TIMER/TIMER_Interface.h"
#include "../MCAL/TIMER/TIMER1_Define.h"
#include "../MCAL/External Interrupt/EX_INT_Int.h"


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
void INT0_InterruptFunction(void);
u16 Enter_Password(void);
extern u8 Flag;
extern u16 LM35_Value;
extern u16 LDR_Value;
u8 Keypad_out=0;
int main(void)
{
	/*Variable Definition*/
	u16 LDR_Result=0;
	u16 LM35_Result=0;

	//set direction of D2 in  portD as input
		DIO_VidSetPinDirection(DIO_PORTD,PIN2,INPUT);
	//activity pull up resistor
		DIO_VidSetPinValue(DIO_PORTD,PIN2,HIGH);
	GIE_Vid_Enable();
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
	/*External Interrupt zero*/
	EX_INT0_INIT();
	INT0_SetCallBack(INT0_InterruptFunction);
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
void INT0_InterruptFunction(void)
{
	LCD_4Bits_VoidClearDisplay();
	u8 count=0;
	u16 Password=Enter_Password();
	while(count<3)
	{
		if(Password==1111)
		{
			LCD_4Bits_VoidClearDisplay();
			Servo_u8DoorState(open);
			LCD_4Bits_SetPosition(0,0);
			LCD_4Bits_DisplayString("The Door is open>>>>");
			_delay_ms(300);
			LCD_4Bits_VoidClearDisplay();
			Servo_u8DoorState(close);
			LCD_4Bits_SetPosition(0,0);
			LCD_4Bits_DisplayString("The Door is Close<<<<<");
			_delay_ms(300);
			break;
		}
		if(Password!=1111)
		{
			Password=Enter_Password();
			count++;
		}


	}
	if(count==3)
	{
		LCD_4Bits_VoidClearDisplay();
		LCD_4Bits_SetPosition(0,0);
		LCD_4Bits_DisplayString("YOU CAN'T ENTERED");
		Buzzer_On_Off(ON);
		_delay_ms(300);
		Buzzer_On_Off(OFF);
	}

}
u16 Enter_Password(void)
{
	u16 Pass=0;
	u8 counter=0;
	while(counter<4)
	{
		Keypad_out=0;
		Keypad_out=KEYPAD_GET_PressedKey();
		if(Keypad_out!=0)
		{
			LCD_4Bits_VidWriteNumber(Keypad_out);
			Pass=Pass*10+Keypad_out;
			counter++;
		}

	}
return Pass;
}
