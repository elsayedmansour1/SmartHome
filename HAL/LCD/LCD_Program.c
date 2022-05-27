#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#include"../../MCAL/DIO/DIO_INT.h"
#include"../../MCAL/DIO/DIO_config.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"
#include "avr/delay.h"


void LCD_VidPulseEnable(void)
{
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */
	_delay_ms(1);
}
void LCD_VidInit(void)
{
	_delay_ms(50);
#if MODE==4
	//DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);  /* Configure the control pins(E,RS,RW) as output pins */
	DIO_VidSetPinDirection(LCD_CTRL_PORT,RS,OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,RW,OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL_PORT,EN,OUTPUT);
	//_delay_ms(1);


		// set only PORT 4~7 pins as outputs
		//DIO_VidSetPortDirection(LCD_DATA_PORT,0xF0);  /* Configure the data port as output port */
		DIO_VidSetPinDirection(LCD_DATA_PORT,PIN4,OUTPUT);
		DIO_VidSetPinDirection(LCD_DATA_PORT,PIN5,OUTPUT);
		DIO_VidSetPinDirection(LCD_DATA_PORT,PIN6,OUTPUT);
		DIO_VidSetPinDirection(LCD_DATA_PORT,PIN7,OUTPUT);
		/*send function set command*/
		LCD_VidWriteCommend(HCLCD_FUNCTION_SET>>4);
		LCD_VidWriteCommend(HCLCD_FUNCTION_SET>>4);
		LCD_VidWriteCommend(HCLCD_FUNCTION_SET);
			_delay_ms(1);
			/*send Display on/off  command*/
			LCD_VidWriteCommend(HCLCD_DISPLAY_ON_OFF>>4);
			LCD_VidWriteCommend(HCLCD_DISPLAY_ON_OFF);
			_delay_ms(1);
			/*send Display Clear  command*/
			LCD_VidWriteCommend(DISPLAY_CLEAR>>4);
			LCD_VidWriteCommend(DISPLAY_CLEAR);
			_delay_ms(2);
			/*send Entry Mode  set command*/
			LCD_VidWriteCommend(HCLCD_ENTRY_MODE_SET>>4);
			LCD_VidWriteCommend(HCLCD_ENTRY_MODE_SET);

#elif MODE==8
	  /*set direction*/
		DIO_VidSetPortDirection(LCD_DATA_PORT,0XFF);
		DIO_VidSetPortDirection(LCD_CTRL_PORT,0x07);

		LCD_VidWriteCommend(0B00111000);//function set
		_delay_ms(1);
		LCD_VidWriteCommend(0B00001100);//screen on
	          _delay_ms(1);
		LCD_VidWriteCommend(0B00000001);//clear display
	          _delay_ms(2);
		LCD_VidWriteCommend(0B00000110);//Mode Set
		LCD_VidWriteCommend(0B00000010);//Return Home
		LCD_VidWriteCommend(0B00000001);//clear display
		LCD_VidWriteCommend(0B00000001);//clear display
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void LCD_VidWriteCommend(u8 LCD_u8Commend)
{
#if MODE==4
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,0); /* Instruction Mode RS=0 */
		DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		DIO_SetNippleValue(4,LCD_DATA_PORT,LCD_u8Commend); /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
		_delay_ms(2);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */

#elif MODE==8
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN0,0);  //RS=0
	DIO_VidSetPinValue(LCD_CTRL_PORT,PIN1,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Commend); //write commend

	LCD_VidPulseEnable();
#else
#error "WRONG CHOOSE THE MODE"
#endif


}
void LCD_VidWriteData(u8 LCD_u8Data)
{
#if MODE==4
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1); /* Instruction Mode RS=0 */
		DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);/* write data to LCD so RW=0 */
		_delay_ms(1);

		//send MOST SIGNIFICANT 4-bits
		DIO_SetNippleValue(4,LCD_DATA_PORT,LCD_u8Data);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1); /* Enable LCD E=1 */
		_delay_ms(2);
		DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0); /* disable LCD E=0 */
#elif MODE==8
		DIO_VidSetPinValue(LCD_CTRL_PORT,RS,1);  //RS=0
	DIO_VidSetPinValue(LCD_CTRL_PORT,RW,0);  //RW=0
	DIO_VidSetPortValue(LCD_DATA_PORT,LCD_u8Data); //write commend

	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,1);  //EN=1
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CTRL_PORT,EN,0);  //EN=0

	_delay_ms(1);     //wait lcd to write letter
#else
#error "WRONG CHOOSE THE MODE"
#endif

}
void LCD_VoidClearDisplay(void)
{
	LCD_VidWriteCommend(0x01>>4);
	LCD_VidWriteCommend(0x01);
	_delay_ms(20);
}
void LCD_4Bits_DisplayCharacter(u8 Copy_u8Data)
{
	LCD_VidWriteData(Copy_u8Data>>4);
	LCD_VidWriteData(Copy_u8Data);
}
void LCD_4Bits_DisplayString(u8* PCopy_u8String)
{
	u8 Loc_u8Count=0;
	while(PCopy_u8String[Loc_u8Count]!=NULL)
	{
		LCD_4Bits_DisplayCharacter(PCopy_u8String[Loc_u8Count]);
		Loc_u8Count++;
	}
}
void LCD_4Bits_VidWriteNumber(u32 LOC_u32num)
{ 	u32 revrese=0;
u8 y;
u8 counter=0;
if(LOC_u32num==0)
{
	LCD_4Bits_DisplayCharacter(48);
}
while(LOC_u32num>0)
{
	revrese=(revrese*10)+(LOC_u32num)%10;
	if(revrese==0)
	{
		 y=0;
		 counter++;
	}
	LOC_u32num=LOC_u32num/10;
}
while(revrese>0)
{
	u8 res=revrese%10;
	LCD_4Bits_DisplayCharacter(res+48);
	revrese=revrese/10;
}
if(y==0)
{
	for(u8 i=0;i<counter;i++)
	{
		LCD_4Bits_DisplayCharacter(48);
	}
}
}
void LCD_Vid4Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
	if((Copy_u8LineNumber==0)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		LCD_VidWriteCommend((128+Copy_u8PositionNumber)>>4);
		LCD_VidWriteCommend((128+Copy_u8PositionNumber));
	}
	else if((Copy_u8LineNumber==1)&&((Copy_u8PositionNumber>=0)&&(Copy_u8PositionNumber<16)))
	{
		LCD_VidWriteCommend((192+Copy_u8PositionNumber)>>4);
		LCD_VidWriteCommend((192+Copy_u8PositionNumber));
	}
	else
	{
	}
}
