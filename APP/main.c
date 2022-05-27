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

		/*hardware*/
#include "../HAL/LCD/LCD_Interface.h"

#include "util/delay.h"


int main(void)
{


	/*LCD initialization*/
	LCD_VidInit();


	LCD_4Bits_DisplayString("WELCOME BACK");
	_delay_ms(1000);
	LCD_4Bits_VidWriteNumber(555555);
	//LCD_VoidClearDisplay();
	while(1)
	{

	}





	return 0;
}
