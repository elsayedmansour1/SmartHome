#ifndef _TCNT2_DEFINE_H_
#define _TCNT2_DEFINE_H_
    /*ALL DEFINITIONS YOU WILL NEED IN TIMNER2 */
                  /*START_TIMER2{*/
                /*MODES*/
#define Normal_2      	     CLR_BIT(TCCR2, WGM21);\
	                         CLR_BIT(TCCR2, WGM20);

#define PWM_Phase_Correct_2  CLR_BIT(TCCR2, WGM21);\
	                         SET_BIT(TCCR2, WGM20);

#define CTC_Mode_2           SET_BIT(TCCR2, WGM21);\
	                         CLR_BIT(TCCR2, WGM20);

#define Fast_PWM_2           SET_BIT(TCCR2, WGM21);\
		                     SET_BIT(TCCR2, WGM20);

#define Normal_Timer2_Mode                   0
#define PWM_Phase_Correct_Timer2_Mode        1
#define CTC_Timer2_Mode       				2
#define Fast_PWM_Timer2_Mode	 				3



/********************************/
#define Timer2_Mode  Fast_PWM_Timer2_Mode
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

    /*Compare Output Mode, non-PWM Mode*/
#define Non_PWM_Normal_OC0_disconnected_2       CLR_BIT(TCCR2,COM21);\
	                                    CLR_BIT(TCCR2,COM20);

#define Toggle_OC0_on_compare_match_2   CLR_BIT(TCCR2,COM21);\
										SET_BIT(TCCR2,COM20);

#define Clear_OC0_on_compare_match_2    SET_BIT(TCCR2,COM21);\
										CLR_BIT(TCCR2,COM20);

#define Set_OC0_on_compare_match_2      SET_BIT(TCCR2,COM21);\
										SET_BIT(TCCR2,COM20);
#define OC0_disconnected_Timer2     0
#define Toggle_OC0_Timer2           1
#define Clear_OC0_Timer2            2
#define Set_OC0_Timer2              3





/*********************************************/
#define Compare_Output_Mode_Timer2 	OC0_disconnected_Timer2
/*********************************************/



/****************************************************************************************************************/
/****************************************************************************************************************/


				/*Compare Output Mode, Fast PWM Mode*/
#define Normal_OC0_disconnected_2        		      CLR_BIT(TCCR2,COM21);\
	                                                  CLR_BIT(TCCR2,COM20);

#define Reserved_2                                    CLR_BIT(TCCR2,COM21);\
	                                                  SET_BIT(TCCR2,COM20);

#define NonInverted_Mode_2     						  SET_BIT(TCCR2,COM21);\
	                                                  CLR_BIT(TCCR2,COM20);

#define Inverted_Mode_2       						  SET_BIT(TCCR2,COM21);\
	                                                  SET_BIT(TCCR2,COM20);

#define Normal_Mode_Timer2	                               0
#define reserved_mode_Timer2	                           1
#define NonInverted_Mode_Timer2	     			           2
#define Inverted_Mode_Timer2	        		           3





/*************************************/

#define Fast_PWM_MODE_2  NonInverted_Mode_Timer2

/************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter_stopped_2              CLR_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
					                         CLR_BIT(TCCR2,CS20);

#define No_prescaling_2                 	 CLR_BIT(TCCR2,CS22);\
											 CLR_BIT(TCCR2,CS21);\
											 SET_BIT(TCCR2,CS20);

#define prescaler_clk_8_2 	          		 CLR_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
	                                         CLR_BIT(TCCR2,CS20);

#define prescaler_clk_64_2    			 	 CLR_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
	                                         SET_BIT(TCCR2,CS20);

#define prescaler_clk_256_2   				 SET_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
	                                         CLR_BIT(TCCR2,CS20);

#define prescaler_clk_1024_2	             SET_BIT(TCCR2,CS22);\
	                                         CLR_BIT(TCCR2,CS21);\
					                         SET_BIT(TCCR2,CS20);

#define External_Clock_on_falling_edge_2 	 SET_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
					                         CLR_BIT(TCCR2,CS20);

#define External_Clock_on_rising_edge_2		 SET_BIT(TCCR2,CS22);\
	                                         SET_BIT(TCCR2,CS21);\
					                         SET_BIT(TCCR2,CS20);
#define 	Timer2_prescaler_0                   0
#define 	Timer2_prescaler_1                   1
#define 	Timer2_prescaler_8                   8
#define 	Timer2_prescaler_64                  64
#define 	Timer2_prescaler_256                 256
#define 	Timer2_prescaler_1024                1024
#define 	Timer2_External_falling_edge         2
#define     Timer2_External_rising_edge	      3




/****************************************/

#define clock_select_2  Timer2_prescaler_256

/****************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/
                    /*INTERRUPT MODE*/
#define Compare_Match_Interrupt_Enable_2      SET_BIT(TIMSK,OCIE2);\
                                              CLR_BIT(TIMSK,TOIE2);

#define Overflow_Interrupt_Enable_2           CLR_BIT(TIMSK,OCIE2);\
                                              SET_BIT(TIMSK,TOIE2);

#define COM_Interrupt_Enable_Timer2    0
#define OVF_Interrupt_Enable_Timer2    1
/**********************************************/

#define INTERRUPT_MODETIMER_2  CM_Interrupt_Enable_Timer2

/*********************************************/
                     /*}END_TIMER2*/
#endif
