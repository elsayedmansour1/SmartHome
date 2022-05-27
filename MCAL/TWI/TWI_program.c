#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_config.h"

void TWI_voidMasterInit(void)
{
	/* Set Prescaler Value */
	CLR_BIT(TWSR,1);
	CLR_BIT(TWSR,0);
	
	/* Set TWBR Value 200KHZ */
	TWBR = 12;
	
	/* Enable ACKnowledgemnet */
	SET_BIT(TWCR,6);
	
	/* Enable TWI */
	SET_BIT(TWCR,2);
}

void   TWI_u8SlaveInit(u8 Copy_u8SlaveAddress)
{
	//u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Set Slave Adress IN TWAR REG */
	TWAR = Copy_u8SlaveAddress << 1;
	
    /* Enable ACKnowledgemnet */
	SET_BIT(TWCR,6);
	
	/* Enable TWI */
	SET_BIT(TWCR,2);
}

TWI_ErrorState   TWI_enuSendStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Send Start Condition */
	SET_BIT(TWCR,5);
	
	/* Clear Flag */
	SET_BIT(TWCR,7);
	
	/* Wait for the Flag */
	while(!(GET_BIT(TWCR,7)));
	
	/* Check ACKnowledgemnt => START CONDITION */
	if((TWSR & 0xF8) != 0x08 )
	{
		Local_enuErrorState = TWI_SC_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendRepeatedStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Send Start Condition */
	SET_BIT(TWCR,5);
	
	/* Clear Flag */
	SET_BIT(TWCR,7);
	
	/* Wait for the Flag */
	while(!(GET_BIT(TWCR,7)));
	
	/* Check ACKnowledgemnt => START CONDITION */
	if((TWSR & 0xF8) != 0x10 )
	{
		Local_enuErrorState = TWI_RSC_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SL Address + Write*/
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,0);
	/* Clear Start Condition */
	CLR_BIT(TWCR,5);
	
	/* Clear Flag */
	SET_BIT(TWCR,7);
	
	/* Wait for the Flag */
	while(!(GET_BIT(TWCR,7)));
	
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR & 0xF8) != 0x18 )
	{
		Local_enuErrorState = TWI_SLA_W_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SL Address + Write*/
	TWDR = Copy_u8SlaveAddress << 1;
	SET_BIT(TWDR,0);
	/* Clear Start Condition */
	CLR_BIT(TWCR,5);
	
	/* Clear Flag */
	SET_BIT(TWCR,7);
	
	/* Wait for the Flag */
	while(!(GET_BIT(TWCR,7)));
	
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR & 0xF8) != 0x40 )
	{
		Local_enuErrorState = TWI_SLA_R_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendDataByte(u8 Copy_u8Data)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = Data + Read*/
	TWDR = Copy_u8Data;

	/* Clear Flag */
	SET_BIT(TWCR,7);
	
	/* Wait for the Flag */
	while(!(GET_BIT(TWCR,7)));
	
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR & 0xF8) != 0x28 )
	{
		Local_enuErrorState = TWI_DATA_W_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuReceiveDataByte(u8 * Copy_pu8ReceivedData)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/* Check pointer */
	if(Copy_pu8ReceivedData != NULL)
	{

		/* Clear Flag */
		SET_BIT(TWCR,7);

		/* Wait for the Flag */
		while(!(GET_BIT(TWCR,7)));

		/* Check ACKnowledgemnt => Slave Address + W */
		if((TWSR & 0xF8) != 0x50 )
		{
			Local_enuErrorState = TWI_DATA_R_ERROR;
		}
		else
		{
			/* Read Data */
			*Copy_pu8ReceivedData = TWDR;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

void TWI_voidSendStopCondition(void)
{
	/* Send Stop Condition */
	SET_BIT(TWCR,4);
	
	/* Clear Flag */
	SET_BIT(TWCR,7);
}
