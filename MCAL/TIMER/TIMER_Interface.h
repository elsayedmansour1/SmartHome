#ifndef _TCNT0_INTERFACE_H_
#define _TCNT0_INTERFACE_H_


void TIMER0_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER0_CM_SetCallBack(void (*LocalPFunc)(void));

void TIMER1_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_A_SetCallBack(void (*LocalPFunc)(void));
void TIMER1_CM_B_SetCallBack(void (*LocalPFunc)(void));

void TIMER2_OV_SetCallBack(void (*LocalPFunc)(void));
void TIMER2_CM_SetCallBack(void (*LocalPFunc)(void));

void TIMER0_INIT(void);
void TIMER1_INIT(void);
void TIMER2_INIT(void);

void TIMER1_Input_Capture_Enterrupt_Enable(void);

void Set_Duty_Cycle_TIMER_0(f32 percentage_Value);
void Set_Duty_Cycle_TIMER_1_A(f32 percentage_Value);
void Set_Duty_Cycle_TIMER_1_B(f32 percentage_Value);
void Set_Duty_Cycle_TIMER_2(f32 percentage_Value);


















#endif
