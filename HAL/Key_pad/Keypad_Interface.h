#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_


#define DIO_Keypad_Columns DIO_PORTC
#define DIO_Keypad_Rows    DIO_PORTA


void KEYPAD_VidInit(void);

u8 KEYPAD_GET_PressedKey(void);













#endif
