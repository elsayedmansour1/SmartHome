/*
 * LCD_Interface.h
 *
 *  Created on: Aug 21, 2020
 *      Author: ELSAYED
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define HCLCD_FUNCTION_SET 	0b00101000
#define	HCLCD_DISPLAY_ON_OFF  0b00001100
#define DISPLAY_CLEAR			0b00000001
#define HCLCD_ENTRY_MODE_SET	0b00000110

/* LCD data length MODE select */
#define MODE 4

/* LCD HW Pins */
#define RS PIN1
#define RW PIN2
#define EN  PIN3
#define LCD_CTRL_PORT DIO_PORTB

/*LCD DATA PINS*/
#define D4 PIN4
#define D5 PIN5
#define D6 PIN6
#define D7 PIN7
#define LCD_DATA_PORT DIO_PORTB


 /* functions  */
void LCD_VidPulseEnable(void);

void LCD_VidInit(void);

void LCD_VidWriteCommend(u8 LOC_u8command);

void LCD_4Bits_VoidClearDisplay(void);
void LCD_4Bits_DisplayCharacter(u8 Copy_u8Data);
void LCD_4Bits_DisplayString(u8* PCopy_u8String);
void LCD_4Bits_VidWriteNumber(u32 LOC_u32num);
void LCD_4Bits_SetPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
#endif /* LCD_INTERFACE_H_ */
