#ifndef _TCNT1_DEFINE_H_
#define _TCNT1_DEFINE_H_
    /*ALL DEFINITIONS YOU WILL NEED IN TIMNER1 */
                  /*START_TIMER1{*/

					/*MODES*/
/*Waveform Generation Mode Bit Description*/
#define NORMAL                                    CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_8_bit                   SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_9_bit                   CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);
				        
#define PWM_Phase_Correct_10_bit                  SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define CTC_1                                     CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_8_bit                            SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_9_bit                            CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define Fast_PWM_10_bit                           SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  CLR_BIT(TCCR1B, WGM13);

#define PWM_Phase_and_Frequency_Correct_1         CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define PWM_Phase_and_Frequency_Correct_2         SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);
				        
#define PWM_Phase_Correct_10                      CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define PWM_Phase_Correct_11                      SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  CLR_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define CTC_2                                  	  CLR_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);
				        
#define Reserved                                  SET_BIT(TCCR1A, WGM10);\
												  CLR_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define Fast_PWM_ICR1                             CLR_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
												  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define Fast_PWM_OCRA1                            SET_BIT(TCCR1A, WGM10);\
												  SET_BIT(TCCR1A, WGM11);\
											  	  SET_BIT(TCCR1B, WGM12);\
												  SET_BIT(TCCR1B, WGM13);

#define NORMAL_Timer_1                              		        0
						
#define PWM_Phase_Correct_8_bit_Timer_1                             1
						
#define PWM_Phase_Correct_9_bit_Timer_1                             2
						
#define PWM_Phase_Correct_10_bit_Timer_1                            3
						
#define CTC_1_Timer_1                                               4
						
#define Fast_PWM_8_bit_Timer_1                                      5
						
#define Fast_PWM_9_bit_Timer_1                                      6
						
#define Fast_PWM_10_bit_Timer_1                                     7
						
#define PWM_Phase_and_Frequency_Correct_1_Timer_1                   8
						
#define PWM_Phase_and_Frequency_Correct_2_Timer_1                   9

#define PWM_Phase_Correct_0_Timer_1									10

#define PWM_Phase_Correct_1_Timer_1									11
		
#define CTC_2_Timer_1                                               12
						
#define Reserved_Timer_1                                            13
						
#define Fast_PWM_ICR1_Timer_1                                          14
						
#define Fast_PWM_OCR1A_Timer_1                                          15

/********************************/
#define Timer1_Mode  Fast_PWM_ICR1_Timer_1
/********************************/


/****************************************************************************************************************/
/****************************************************************************************************************/

				/*Compare Output Mode, Non-PWM*/
#define Normal_port_operation_1       CLR_BIT(TCCR1A, COM1A0);\
	                                  CLR_BIT(TCCR1A, COM1A1);\
	                                  CLR_BIT(TCCR1A, COM1B0);\
	                                  CLR_BIT(TCCR1A, COM1B1);

#define Toggle_OC1A_OC1B_1            SET_BIT(TCCR1A, COM1A0);\
									  CLR_BIT(TCCR1A, COM1A1);\
	                            	  SET_BIT(TCCR1A, COM1B0);\
	                            	  CLR_BIT(TCCR1A, COM1B1);

#define Non_Inverted_1                CLR_BIT(TCCR1A, COM1A0);\
									  SET_BIT(TCCR1A, COM1A1);\
									  CLR_BIT(TCCR1A, COM1B0);\
									  SET_BIT(TCCR1A, COM1B1);

#define Inverted_1                    SET_BIT(TCCR1A, COM1A0);\
									  SET_BIT(TCCR1A, COM1A1);\
									  SET_BIT(TCCR1A, COM1B0);\
									  SET_BIT(TCCR1A, COM1B1);

#define Normal_port_operation_Timer1	0

#define Toggle_OC1A_OC1B_Timer1         1

#define Non_Inverted_Timer1             2

#define Inverted_Timer1                 3

/***********************************************/
#define Compare_Output_Mode  Non_Inverted_Timer1
/**********************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/


			/*Compare Output Mode, Fast PWM*/
#define PWM_Normal_port_operation_1          CLR_BIT(TCCR1A, COM1A0);\
											 CLR_BIT(TCCR1A, COM1A1);\
											 CLR_BIT(TCCR1A, COM1B0);\
											 CLR_BIT(TCCR1A, COM1B1);

#define PWM_Toggle_OC1A_OC1B_1      		 SET_BIT(TCCR1A, COM1A0);\
											 CLR_BIT(TCCR1A, COM1A1);\
											 SET_BIT(TCCR1A, COM1B0);\
											 CLR_BIT(TCCR1A, COM1B1);

#define PWM_Non_Inverted_1           		 CLR_BIT(TCCR1A, COM1A0);\
											 SET_BIT(TCCR1A, COM1A1);\
											 CLR_BIT(TCCR1A, COM1B0);\
											 SET_BIT(TCCR1A, COM1B1);

#define PWM_Inverted_1              		 SET_BIT(TCCR1A, COM1A0);\
											 SET_BIT(TCCR1A, COM1A1);\
											 SET_BIT(TCCR1A, COM1B0);\
											 SET_BIT(TCCR1A, COM1B1);

#define PWM_Normal_port_operation_Timer1		  0

#define PWM_Toggle_OC1A_OC1B_Timer1               1

#define PWM_Non_Inverted_Timer1                   2

#define PWM_Inverted_Timer1                       3

/****************************************************/
#define PWM_Compare_Output_Mode  Non_Inverted_Timer1
/****************************************************/


/****************************************************************************************************************/
/****************************************************************************************************************/


/*Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM*/
#define PHC_PWM_Normal_port_operation_1         CLR_BIT(TCCR1A, COM1A0);\
												CLR_BIT(TCCR1A, COM1A1);\
												CLR_BIT(TCCR1A, COM1B0);\
												CLR_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Toggle_OC1A_OC1B_1              SET_BIT(TCCR1A, COM1A0);\
												CLR_BIT(TCCR1A, COM1A1);\
												SET_BIT(TCCR1A, COM1B0);\
												CLR_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Non_Inverted_1                  CLR_BIT(TCCR1A, COM1A0);\
												SET_BIT(TCCR1A, COM1A1);\
												CLR_BIT(TCCR1A, COM1B0);\
												SET_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Inverted_1                      SET_BIT(TCCR1A, COM1A0);\
												SET_BIT(TCCR1A, COM1A1);\
												SET_BIT(TCCR1A, COM1B0);\
												SET_BIT(TCCR1A, COM1B1);

#define PHC_PWM_Normal_port_operation_Timer1	      0

#define PHC_PWM_Toggle_OC1A_OC1B_Timer1               1

#define PHC_PWM_Non_Inverted_Timer1                   2

#define PHC_PWM_Inverted_Timer1                       3

/****************************************************/
#define PHC_PWM_Compare_Output_Mode  Non_Inverted_Timer1
/****************************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/

                    /*Clock Select*/
#define Timer_Counter_stopped_1          			  CLR_BIT(TCCR1B,CS12);\
	                                                  CLR_BIT(TCCR1B,CS11);\
	                                                  CLR_BIT(TCCR1B,CS10);
							     
#define No_prescaling_1                 	   	 	  CLR_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);
							     
#define prescaler_clk_8_1 	          				  CLR_BIT(TCCR1B,CS12);\
													  SET_BIT(TCCR1B,CS11);\
													  CLR_BIT(TCCR1B,CS10);

#define prescaler_clk_64_1    						  CLR_BIT(TCCR1B,CS12);\
	                                                  SET_BIT(TCCR1B,CS11);\
	                                                  SET_BIT(TCCR1B,CS10);
							     
#define prescaler_clk_256_1   		                  SET_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  CLR_BIT(TCCR1B,CS10);
							     
#define prescaler_clk_1024_1 	              	 	  SET_BIT(TCCR1B,CS12);\
													  CLR_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);
							     
#define External_Clock_on_falling_edge_1 	          SET_BIT(TCCR1B,CS12);\
	                                                  SET_BIT(TCCR1B,CS11);\
	                                                  CLR_BIT(TCCR1B,CS10);
							     
#define External_Clock_on_rising_edge_1		 	      SET_BIT(TCCR1B,CS12);\
												   	  SET_BIT(TCCR1B,CS11);\
													  SET_BIT(TCCR1B,CS10);

#define 	Timer1_prescaler_0                   0
#define 	Timer1_prescaler_1                   1
#define 	Timer1_prescaler_8                   8
#define 	Timer1_prescaler_64                  64
#define 	Timer1_prescaler_256                 256
#define 	Timer1_prescaler_1024                1024
#define 	Timer1_External_falling_edge         2
#define   Timer1_External_rising_edge	     	 3




/****************************************/

#define clock_select_Timer1  Timer1_prescaler_256

/****************************************/

/****************************************************************************************************************/
/****************************************************************************************************************/


                    /*INTERRUPT MODE*/

#define Input_Capture_Interrupt_Enable          SET_BIT(TIMSK,TICIE1);

#define Compare_A_Match_Interrupt_Enable_1      SET_BIT(TIMSK,OCIE1A);
                                             

#define Compare_B_Match_Interrupt_Enable_1      SET_BIT(TIMSK,OCIE1B);
                                             
				      
#define Overflow_Interrupt_Enable_1            	SET_BIT(TIMSK,TOIE1);
                                             

#define COM_Interrupt_Enable_Timer1    0
#define OVF_Interrupt_Enable_Timer1    1
/**********************************************/

#define INTERRUPT_MODE_Timer1  CM_Interrupt_Enable_Timer1

/*********************************************/
		/*}END_TIMER1*/
#endif
