/*
 * TIMER_CONFIG.h
 *
 *  Created on: May 1, 2022
 *      Author: elsay
 */

#ifndef MCAL_TIMER_TIMER_CONFIG_H_
#define MCAL_TIMER_TIMER_CONFIG_H_

                /*TCCR0 REGISTER*/
#define FOC0      7 //force output compare

#define WGM00     6 //waveform generation mode 00
#define WGM01     3 //waveform generation mode 01

#define COM01     5 //compare output mode 1
#define COM00     4 //compare output mode 0

#define CS02      2 //clock selection 02
#define CS01      1 //clock selection 01
#define CS00      0 //clock selection 00
/****************************************************************************************************************/
/****************************************************************************************************************/
            /*TIMSK REGISTER*/
#define OCIE2     7  //output compare Interrupt Enable in TIMER 2
#define TOIE2     6  //TIMER 2 overflow Interrupt Enable
#define TICIE1    5  //Input Capture Interrupt Enable in TIMER 1
#define OCIE1A    4  //output compare A Interrupt Enable in TIMER 1
#define OCIE1B    3  //output compare B Interrupt Enable in TIMER 1
#define TOIE1     2  //TIMER 1 overflow Interrupt Enable
#define OCIE0     1  //output compare Interrupt Enable in TIMER 0
#define TOIE0     0  //TIMER 0 overflow Interrupt Enable

/****************************************************************************************************************/
/****************************************************************************************************************/
             /*TCCR2*/
#define FOC2     7   //force output compare
#define WGM20    6   //waveform generation mode 20
#define COM21    5   //compare output mode 1
#define COM20    4   //compare output mode 0
#define WGM21    3   //waveform generation mode 21
#define CS22     2   //clock selection 22
#define CS21     1   //clock selection 21
#define CS20     0   //clock selection 20

/****************************************************************************************************************/
/****************************************************************************************************************/

/*Timer/Counter1 Control Register A  TCCR1A*/
#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4
#define FOC1A    3
#define FOC1B    2
#define WGM11    1
#define WGM10    0

/*Timer/Counter1 Control Register B TCCR1B*/
#define ICNC1     7
#define ICES1     6
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0

                /*TCCR2*/
#define FOC2     7   //force output compare
#define WGM20    6   //waveform generation mode 20
#define COM21    5   //compare output mode 1
#define COM20    4   //compare output mode 0
#define WGM21    3   //waveform generation mode 21
#define CS22     2   //clock selection 22
#define CS21     1   //clock selection 21
#define CS20     0   //clock selection 20



/************************************************************************************************************************************/
/************************************************************************************************************************************/


#define ISR_EXINT0()     void __vector_1(void)__attribute__((signal));\
	                     void __vector_1(void)
#define ISR_EXINT1()     void __vector_2(void)__attribute__((signal));\
	                     void __vector_2(void)
#define ISR_EXINT2()     void __vector_3(void)__attribute__((signal));\
	                     void __vector_3(void)

#define ISR_TMR2_Comp()  void __vector_4(void)__attribute__((signal));\
	                     void __vector_4(void)
#define ISR_TMR2_OVF()   void __vector_5(void)__attribute__((signal));\
						 void __vector_5(void)

#define ISR_TMR1_Capt()  void __vector_6(void)__attribute__((signal));\
	                     void __vector_6(void)
#define ISR_TMR1_CompA() void __vector_7(void)__attribute__((signal));\
	                     void __vector_7(void)
#define ISR_TMR1_CompB() void __vector_8(void)__attribute__((signal));\
	                     void __vector_8(void)

#define ISR_TMR1_OVF()   void __vector_9(void)__attribute__((signal));\
	                     void __vector_9(void)

#define ISR_TMR0_Comp()  void __vector_10(void)__attribute__((signal));\
	                     void __vector_10(void)
#define ISR_TMR0_OVF()   void __vector_11(void)__attribute__((signal));\
	                     void __vector_11(void)

#endif /* MCAL_TIMER_TIMER_CONFIG_H_ */
