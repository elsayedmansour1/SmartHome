#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_REG.h"
#include "../../MCAL/DIO/DIO_INT.h"
#include "../../MCAL/DIO/DIO_config.h"
#include <avr/delay.h>
#include "Keypad_Interface.h"



void KEYPAD_VidInit(void)
{
	/*we will set the first 4-pins as output by set 1 in direction*/
	DIO_VidSetPinDirection(DIO_Keypad_Columns,PIN4,OUTPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Columns,PIN5,OUTPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Columns,PIN6,OUTPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Columns,PIN7,OUTPUT);
	 /*and set the second 4-pins as input by set 0 in direction*/
	DIO_VidSetPinDirection(DIO_Keypad_Rows,PIN4,INPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Rows,PIN5,INPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Rows,PIN6,INPUT);
	DIO_VidSetPinDirection(DIO_Keypad_Rows,PIN7,INPUT);
	/*the 4 input pins we will activate pull up resistor */
	DIO_VidSetPinValue(DIO_Keypad_Rows,PIN4,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Rows,PIN5,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Rows,PIN6,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Rows,PIN7,HIGH);
	/*the 4 output pins we will set value as 1*/
	DIO_VidSetPinValue(DIO_Keypad_Columns,PIN4,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Columns,PIN5,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Columns,PIN6,HIGH);
	DIO_VidSetPinValue(DIO_Keypad_Columns,PIN7,HIGH);

}
u8 KEYPAD_GET_PressedKey(void)
{   u8 keypad_array[4][4]={{ 1, 2, 3, 4},
		                   { 5, 6, 7, 8},
						   { 9,10,11,12},
						   {13,14,15,16}};
	/*Columns for output pins*/
	 /*Rows for input pins*/
	u8 col,row;
	/*keypad_out variable for Get the pressed switch*/
	u8 keypad_out=0;
	for(col=4;col<8;col++)
	{
		/*we will activate only one column at time*/
			/*by change his value from 1 to 0*/
		DIO_VidSetPinValue	( DIO_Keypad_Columns, col, 0);
		for(row=4;row<8;row++)
		{
			/*every time you change the column value */
			     /*you will check all Rows */
			/*if any Row his value changed that mean*/
				/*there is key is pressed*/
			if(DIO_u8GetPinValue(DIO_Keypad_Rows,row)==0)
			{
				/*we will mapping between the pressed key*/
					/*and the value in keypad array*/
				keypad_out= keypad_array[row-4][col-4];
				/* if the key is still pressed you will not  */
				      /* go to for the next instruction*/
				while(DIO_u8GetPinValue(DIO_Keypad_Rows,row)==0);

				_delay_ms(50);
			}



		}
			  /*if you check in all rows in this column*/
		/*you need to deactivate it to go to the next column*/
		DIO_VidSetPinValue	( DIO_Keypad_Columns, col, 1);
	}
/*if there is any switch is pressed the value of keypad_out variable*/
	/*will change from 0 to the mapping value in keypad_array*/
return keypad_out;
}

