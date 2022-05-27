#ifndef _TCNT0_DEFINE_H_
#define _TCNT0_DEFINE_H_


     /*ALL DEFINITIONS YOU WILL NEED IN TIMNER0 */
                  /*START_TIMER0*/
                /*MODES*/
#define Normal_0      	   			CLR_BIT(TCCR0, WGM01);\
									CLR_BIT(TCCR0, WGM00);

#define PWM_Phase_Correct_0  	    CLR_BIT(TCCR0, WGM01);\
									SET_BIT(TCCR0, WGM00);

#define CTC_Mode_0           		SET_BIT(TCCR0, WGM01);\
									CLR_BIT(TCCR0, WGM00);

#define Fast_PWM_0         			SET_BIT(TCCR0, WGM01);\
		                   	   	   	SET_BIT(TCCR0, WGM00);

#define Normal_Timer0_Mode                   0
#define PWM_Phase_Correct_Timer0_Mode        1
#define CTC_Timer0_Mode       				2
#define Fast_PWM_Timer0_Mode	 				3



/********************************/
#define Timer0_Mode  Fast_PWM_Timer0_Mode
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

    /*Compare Output Mode, non-PWM Mode*/
#define Non_PWM_Normal_OC0_disconnected_0         CLR_BIT(TCCR0,COM01);\
	                                    		  CLR_BIT(TCCR0,COM00);

#define Toggle_OC0_on_compare_match_0    		 CLR_BIT(TCCR0,COM01);\
												SET_BIT(TCCR0,COM00);

#define Clear_OC0_on_compare_match_0     		 SET_BIT(TCCR0,COM01);\
										  	  	  CLR_BIT(TCCR0,COM00);

#define Set_OC0_on_compare_match_0        		SET_BIT(TCCR0,COM01);\
												SET_BIT(TCCR0,COM00);
#define OC0_disconnected_Timer0     0
#define Toggle_OC0_Timer0           1
#define Clear_OC0_Timer0            2
#define Set_OC0_Timer0              3





/*********************************************/
#define Compare_Output_Mode_Timer0   OC0_disconnected_Timer0
/*********************************************/



/****************************************************************************************************************/
/****************************************************************************************************************/
             /*Compare Output Mode, Fast PWM Mode*/
#define Normal_OC0_disconnected_0        		          CLR_BIT(TCCR0,COM01);\
	                                                  	  CLR_BIT(TCCR0,COM00);

#define Reserved_0                                      CLR_BIT(TCCR0,COM01);\
	                                                  SET_BIT(TCCR0,COM00);

#define NonInverted_Mode_0     						  SET_BIT(TCCR0,COM01);\
	                                                  CLR_BIT(TCCR0,COM00);

#define Inverted_Mode_0       						  SET_BIT(TCCR0,COM01);\
	                                                  SET_BIT(TCCR0,COM00);

#define Normal_Mode_Timer0	                               0
#define reserved_mode_Timer0	                           1
#define NonInverted_Mode_Timer0	     			           2
#define Inverted_Mode_Timer0	        		           3





/*************************************/

#define Fast_PWM_MODE_0  NonInverted_Mode_Timer0

/************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter stopped_0          		 CLR_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
					                         CLR_BIT(TCCR0,CS00);

#define No_prescaling_0                 	   	 CLR_BIT(TCCR0,CS02);\
											 CLR_BIT(TCCR0,CS01);\
											 SET_BIT(TCCR0,CS00);

#define prescaler_clk_8_0 	          		 CLR_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
	                                         CLR_BIT(TCCR0,CS00);

#define prescaler_clk_64_0    			 	 CLR_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
	                                         SET_BIT(TCCR0,CS00);

#define prescaler_clk_256_0   				 SET_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
	                                         CLR_BIT(TCCR0,CS00);

#define prescaler_clk_1024_0 	              	 SET_BIT(TCCR0,CS02);\
	                                         CLR_BIT(TCCR0,CS01);\
					                         SET_BIT(TCCR0,CS00);

#define External_Clock_on_falling_edge_0 	     SET_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
					                         CLR_BIT(TCCR0,CS00);

#define External_Clock_on_rising_edge_0		 SET_BIT(TCCR0,CS02);\
	                                         SET_BIT(TCCR0,CS01);\
					                         SET_BIT(TCCR0,CS00);

#define 	Timer0_prescaler_0                   0
#define 	Timer0_prescaler_1                   1
#define 	Timer0_prescaler_8                   8
#define 	Timer0_prescaler_64                  64
#define 	Timer0_prescaler_256                 256
#define 	Timer0_prescaler_1024                1024
#define 	Timer0_External_falling_edge         2
#define   Timer0_External_rising_edge	       3




/****************************************/

#define clock_select_0  Timer0_prescaler_256

/****************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/
                    /*INTERRUPT MODE*/
#define Compare_Match_Interrupt_Enable_0        SET_BIT(TIMSK,OCIE0);\
                                              CLR_BIT(TIMSK,TOIE0);

#define Overflow_Interrupt_Enable_0           CLR_BIT(TIMSK,OCIE0);\
                                              SET_BIT(TIMSK,TOIE0);

#define COM_Interrupt_Enable_Timer0    0
#define OVF_Interrupt_Enable_Timer0    1
/*********************************************/

#define INTERRUPT_MODE_TIMER_0  CM_Interrupt_Enable_Timer0

/*********************************************/
                     /*}END_TIMER0*/
#endif
