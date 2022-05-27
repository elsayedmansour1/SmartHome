#ifndef _EX_INT_INTERFACE_H_
#define _EX_INT_INTERFACE_H_

void INT0_SetCallBack(void(*LocPFunc)(void));
void INT1_SetCallBack(void(*LocPFunc)(void));
void INT2_SetCallBack(void(*LocPFunc)(void));

void EX_INT0_INIT(void);

void EX_INT1_INIT(void);

void EX_INT2_INIT(void);



















#endif