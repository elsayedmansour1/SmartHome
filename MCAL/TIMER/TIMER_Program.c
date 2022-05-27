#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_Register.h"
#include "TIMER_Interface.h"
#include"TIMER_CONFIG.h"
#include"TIMER0_Define.h"
#include"TIMER1_Define.h"
#include"TIMER2_Define.h"



static void (*GPFunc_T0)(void)=NULL;
static void (*GPFunc_T2)(void)=NULL;
static void (*GPFunc_T1)(void)=NULL;


void TIMER0_OV_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T0=LocalPFunc;
}
void TIMER0_CM_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T0=LocalPFunc;
}
////////////////////////////////////////////////////
void TIMER1_OV_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
void TIMER1_CM_A_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
void TIMER1_CM_B_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T1=LocalPFunc;
}
////////////////////////////////////////////////////
void TIMER2_OV_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T2=LocalPFunc;
}
void TIMER2_CM_SetCallBack(void (*LocalPFunc)(void))
{
	GPFunc_T2=LocalPFunc;
}
////////////////////////////////////////////////////
ISR_TMR0_OVF()
{
	if(GPFunc_T0!=NULL)
	{
		GPFunc_T0();
	}
}
ISR_TMR0_Comp()
{
	if(GPFunc_T0!=NULL)
	{
		GPFunc_T0();
	}
}
////////////////////////////////////////////////////
ISR_TMR1_OVF()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
ISR_TMR1_CompA()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
ISR_TMR1_CompB()
{
	if(GPFunc_T1!=NULL)
		{
			GPFunc_T1();
		}
}
////////////////////////////////////////////////////
ISR_TMR2_OVF()
{
	if(GPFunc_T2!=NULL)
	{
		GPFunc_T2();
	}
}
ISR_TMR2_Comp()
{
	if(GPFunc_T2!=NULL)
	{
		GPFunc_T2();
	}
}
////////////////////////////////////////////////////
/*******************************************************************************************************/
void TIMER0_INIT(void)
{
#if Timer0_Mode==Normal_Timer0_Mode
	TCNT0=192;                       //YOU SHOULD CHANGE THIS BIT
	Normal_0;
	prescaler_clk_8_0;
	Non_PWM_Normal_OC0_disconnected_0;
	Overflow_Interrupt_Enable_0;
#elif Timer0_Mode==CTC_Timer0_Mode
	OCR0=250;                     //YOU SHOULD CHANGE THIS BIT
	CTC_Mode_0;
	prescaler_clk_8_0;
	Non_PWM_Normal_OC0_disconnected_0;
	Compare_Match_Interrupt_Enable_0;
#elif Timer0_Mode==Fast_PWM_Timer0_Mode
	Fast_PWM_0;
	NonInverted_Mode_0;
	prescaler_clk_256_0;
#elif Timer0_Mode==PWM_Phase_Correct_Timer0_Mode
	PWM_Phase_Correct_0;
	prescaler_clk_256_0;

#else
#error "WRONG CHOOSE"
#endif

}
/*******************************************************************************************************/
void TIMER1_INIT(void)
{
#if Timer1_Mode==NORMAL_Timer_1
	TCNT1=25206;
	NORMAL;
	prescaler_clk_8_1;
	Normal_port_operation_1;
	Overflow_Interrupt_Enable_1;
#elif Timer1_Mode==PWM_Phase_Correct_8_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_9_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_10_bit_Timer_1
#elif Timer1_Mode==CTC_1_Timer_1
	/*IN CTC MODE YOU CAN ONLY WORK WITH OCR1A
	 * YOU CAN'T WORK OUTPUT COMPARE MATCH B*/
	OCR1A=62500;
	CTC_1;
	prescaler_clk_8_1;
	Normal_port_operation_1;
	Compare_A_Match_Interrupt_Enable_1;
#elif Timer1_Mode==Fast_PWM_8_bit_Timer_1
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
#elif Timer1_Mode==PWM_Phase_and_Frequency_Correct_1_Timer_1
#elif Timer1_Mode==PWM_Phase_and_Frequency_Correct_2_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_0_Timer_1
#elif Timer1_Mode==PWM_Phase_Correct_1_Timer_1
#elif Timer1_Mode==CTC_2_Timer_1

#elif Timer1_Mode==Reserved_Timer_1
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	ICR1=19999;		// For 50 Hz for servo motor
	prescaler_clk_8_1;
	Fast_PWM_ICR1;
	PWM_Non_Inverted_1;
#elif Timer1_Mode==Fast_PWM_OCR1A_Timer_1
#else
#error "WRONG CHOOSE"
#endif

}
/*******************************************************************************************************/
void TIMER2_INIT(void)
{
#if Timer2_Mode==Normal_Timer2_Mode
	TCNT2=192;                              //YOU SHOULD CHANGE THIS BIT
	Normal_2;
	prescaler_clk_8_2;
	Non_PWM_Normal_OC0_disconnected_2;
	Overflow_Interrupt_Enable_2;
#elif Timer2_Mode==CTC_Timer2_Mode
	OCR2=250;                     //YOU SHOULD CHANGE THIS BIT
	CTC_Mode_2;
	prescaler_clk_8_2;
	Non_PWM_Normal_OC0_disconnected_2;
	Compare_Match_Interrupt_Enable_2;
#elif Timer2_Mode==Fast_PWM_Timer2_Mode
	Fast_PWM_2;
	NonInverted_Mode_2;
	prescaler_clk_256_2;
#elif Timer2_Mode==PWM_Phase_Correct_Timer2_Mode
	PWM_Phase_Correct_2;
	prescaler_clk_256_2;

#else
#error "WRONG CHOOSE"

#endif
}
/********************************************************************************************************/
void TIMER1_Input_Capture_Enterrupt_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
/********************************************************************************************************/
void Set_Duty_Cycle_TIMER_0(f32 percentage_Value)
{
	percentage_Value=percentage_Value/100;
	OCR0=(percentage_Value*255)-1;

}
void Set_Duty_Cycle_TIMER_1_A(f32 percentage_Value)
{
/*#if Timer1_Mode==Normal_Timer1_Mode
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*65535)-1;*/
#if Timer1_Mode==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*256)-1;
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*512)-1;
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*1024)-1;
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A=(percentage_Value*ICR1)-1;
#else
#error "WRONG CHOOSE"

#endif

}
void Set_Duty_Cycle_TIMER_1_B(f32 percentage_Value)
{
/*#if Timer1_Mode==Normal_Timer1_Mode
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*65535)-1;*/
#if Timer1_Mode==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*256)-1;
#elif Timer1_Mode==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*512)-1;
#elif Timer1_Mode==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*1024)-1;
#elif Timer1_Mode==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B=(percentage_Value*ICR1)-1;
#else
#error "WRONG CHOOSE"

#endif

}
void Set_Duty_Cycle_TIMER_2(f32 percentage_Value)
{
	percentage_Value=percentage_Value/100;
	OCR2=(percentage_Value*255)-1;

}

