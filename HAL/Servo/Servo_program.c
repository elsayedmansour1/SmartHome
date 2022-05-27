/*
 * Servo_program.c
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
#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../MCAL/TIMER/TIMER1_Define.h"
#include "util/delay.h"
#include "Servo_Interface.h"
void Servo_VoidInit(void)
{
	/*select the Pin5 in port D as output for Servo*/
	DIO_VidSetPinDirection(DIO_PORTD,PIN5,OUTPUT);
	/*Timer 1 Initialization*/
	TIMER1_INIT();
	/*to make sure the door is closed*/
	Set_Duty_Cycle_TIMER_1_A(2.5);
	_delay_ms(100);
}
void Servo_u8DoorState(u8 copy_DoorState)
{
	if(copy_DoorState==open)
	{
		Set_Duty_Cycle_TIMER_1_A(7.5);

	}
	else if(copy_DoorState==close)
	{
		Set_Duty_Cycle_TIMER_1_A(2.5);
	}

}
