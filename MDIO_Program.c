/* LIB Layer */
#include "STD_Types.h"
#include "BIT_MATH.h"

/* MCAL Layer Include*/
#include "MDIO_Config.h"
#include "MDIO_Interface.h"
#include "MDIO_Private.h"

int main(int argc, char **argv)
{
}

/* Set Pin Direction */
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirec)
{
	u8 Local_u8ErrorSate = STD_TYPE_OK;
	if (Copy_u8PinId <= MDIO_Pin_7 && Copy_u8PortId <= MDIO_PORTD && Copy_u8PinDirec <= MDIO_INPUT_PULLED_UP)
	{
		/* Select Pin Direction */
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			if (Copy_u8PinDirec == MDIO_OUTPUT)
			{
				/*Set DDRA Pin in DDRA Reg*/
				SET_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_FLOATING)
			{
				/*Clear DDRA Pin in DDRA Reg*/
				CLEAR_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_PULLED_UP)
			{
				/*clear DDRA Pin in DDRA Reg*/
				CLEAR_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);
				/*Set PORTA Pin in DDRA Reg*/
				SET_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8PinDirec == MDIO_OUTPUT)
			{
				/*Set DDRB Pin in DDRB Reg*/
				SET_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_FLOATING)
			{
				/*Clear DDRB Pin in DDRB Reg*/
				CLEAR_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_PULLED_UP)
			{
				/*clear DDRB Pin in DDRB Reg*/
				CLEAR_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);
				/*Set PORTB Pin in DDRB Reg*/
				SET_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8PinDirec == MDIO_OUTPUT)
			{
				/*Set DDRC Pin in DDRC Reg*/
				SET_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_FLOATING)
			{
				/*Clear DDRC Pin in DDRC Reg*/
				CLEAR_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_PULLED_UP)
			{
				/*clear DDRC Pin in DDRC Reg*/
				CLEAR_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);
				/*Set PORTC Pin in DDRC Reg*/
				SET_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8PinDirec == MDIO_OUTPUT)
			{
				/*Set DDRD Pin in DDRD Reg*/
				SET_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_FLOATING)
			{
				/*Clear DDRD Pin in DDRD Reg*/
				CLEAR_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinDirec == MDIO_INPUT_PULLED_UP)
			{
				/*clear DDRD Pin in DDRD Reg*/
				CLEAR_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);
				/*Set PORTD Pin in DDRD Reg*/
				SET_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		default:
			Local_u8ErrorSate = STD_TYPE_NOK;
			break;
		}
	}
	return Local_u8ErrorSate;
}

/* Set Port Direction */
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirec)
{
	u8 Local_u8ErrorSate = STD_TYPE_OK;
	if (Copy_u8PortId <= MDIO_PORTD && Copy_u8PortDirec <= MDIO_INPUT_PULLED_UP)
	{
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			if (Copy_u8PortDirec == MDIO_OUTPUT)
			{
				/* Set all Port A pins as Output */
				PRIVATE_DDRA_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_FLOATING)
			{
				/* Set all Port A pins as Input (Floating) */
				PRIVATE_DDRA_REG = MDIO_ALL_PORT_INPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_PULLED_UP)
			{
				/* Set all Port A pins as Input (Pulled-Up) */
				PRIVATE_DDRA_REG = MDIO_ALL_PORT_INPUT;
				/* Enable Pull-Up on all Port A pins */
				PRIVATE_PORTA_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8PortDirec == MDIO_OUTPUT)
			{
				/* Set all Port B pins as Output */
				PRIVATE_DDRB_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_FLOATING)
			{
				/* Set all Port B pins as Input (Floating) */
				PRIVATE_DDRB_REG = MDIO_ALL_PORT_INPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_PULLED_UP)
			{
				/* Set all Port B pins as Input (Pulled-Up) */
				PRIVATE_DDRB_REG = MDIO_ALL_PORT_INPUT;
				/* Enable Pull-Up on all Port B pins */
				PRIVATE_PORTB_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8PortDirec == MDIO_OUTPUT)
			{
				/* Set all Port C pins as Output */
				PRIVATE_DDRC_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_FLOATING)
			{
				/* Set all Port C pins as Input (Floating) */
				PRIVATE_DDRC_REG = MDIO_ALL_PORT_INPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_PULLED_UP)
			{
				/* Set all Port C pins as Input (Pulled-Up) */
				PRIVATE_DDRC_REG = MDIO_ALL_PORT_INPUT;
				/* Enable Pull-Up on all Port C pins */
				PRIVATE_PORTC_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8PortDirec == MDIO_OUTPUT)
			{
				/* Set all Port D pins as Output */
				PRIVATE_DDRD_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_FLOATING)
			{
				/* Set all Port D pins as Input (Floating) */
				PRIVATE_DDRD_REG = MDIO_ALL_PORT_INPUT;
			}
			else if (Copy_u8PortDirec == MDIO_INPUT_PULLED_UP)
			{
				/* Set all Port D pins as Input (Pulled-Up) */
				PRIVATE_DDRD_REG = MDIO_ALL_PORT_INPUT;
				/* Enable Pull-Up on all Port D pins */
				PRIVATE_PORTD_REG = MDIO_ALL_PORT_OUTPUT;
			}
			else
			{
				Local_u8ErrorSate = STD_TYPE_NOK;
			}
			break;
		default:
			Local_u8ErrorSate = STD_TYPE_NOK;
			break;
		}
	}
	return Local_u8ErrorSate;
}
/* Set Pin Value */
u8 MDIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPE_OK; // Corrected spelling from ErrorSate to ErrorState
	if (Copy_u8PortId <= MDIO_PORTD && Copy_u8PinId <= MDIO_Pin_7 && Copy_u8PinValue <= MDIO_HIGH)
	{
		/* Set Pin Value */
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			if (Copy_u8PinValue == MDIO_HIGH)
			{
				/* Set PORTA Pin in PORTA Reg */
				SET_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinValue == MDIO_LOW)
			{
				/* Clear PORTA Pin in PORTA Reg */
				CLEAR_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8PinValue == MDIO_HIGH)
			{
				/* Set PORTB Pin in PORTB Reg */
				SET_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinValue == MDIO_LOW)
			{
				/* Clear PORTB Pin in PORTB Reg */
				CLEAR_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8PinValue == MDIO_HIGH)
			{
				/* Set PORTC Pin in PORTC Reg */
				SET_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinValue == MDIO_LOW)
			{
				/* Clear PORTC Pin in PORTC Reg */
				CLEAR_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8PinValue == MDIO_HIGH)
			{
				/* Set PORTD Pin in PORTD Reg */
				SET_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);
			}
			else if (Copy_u8PinValue == MDIO_LOW)
			{
				/* Clear PORTD Pin in PORTD Reg */
				CLEAR_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		default:
			Local_u8ErrorState = STD_TYPE_NOK;
			break;
		}
	}
	return Local_u8ErrorState;
}

/* Set Port Value */
u8 MDIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPE_OK; // Corrected spelling from ErrorSate to ErrorState
	if ((Copy_u8PortId <= MDIO_PORTD) && ((Copy_u8PortValue == MDIO_ALL_PORT_HIGH) || (Copy_u8PortValue == MDIO_ALL_PORT_LOW)))
	{
		/* Set Port Value */
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			if (Copy_u8PortValue == MDIO_ALL_PORT_HIGH)
			{
				/* Set PORTA Register to HIGH */
				PRIVATE_PORTA_REG = MDIO_ALL_PORT_HIGH;
			}
			else if (Copy_u8PortValue == MDIO_ALL_PORT_LOW)
			{
				/* Set PORTA Register to LOW */
				PRIVATE_PORTA_REG = MDIO_ALL_PORT_LOW;
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8PortValue == MDIO_ALL_PORT_HIGH)
			{
				/* Set PORTB Register to HIGH */
				PRIVATE_PORTB_REG = MDIO_ALL_PORT_HIGH;
			}
			else if (Copy_u8PortValue == MDIO_ALL_PORT_LOW)
			{
				/* Set PORTB Register to LOW */
				PRIVATE_PORTB_REG = MDIO_ALL_PORT_LOW;
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8PortValue == MDIO_ALL_PORT_HIGH)
			{
				/* Set PORTC Register to HIGH */
				PRIVATE_PORTC_REG = MDIO_ALL_PORT_HIGH;
			}
			else if (Copy_u8PortValue == MDIO_ALL_PORT_LOW)
			{
				/* Set PORTC Register to LOW */
				PRIVATE_PORTC_REG = MDIO_ALL_PORT_LOW; // Corrected register name from PRIVATE_PORTB_REG to PRIVATE_PORTC_REG
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8PortValue == MDIO_ALL_PORT_HIGH)
			{
				/* Set PORTD Register to HIGH */
				PRIVATE_PORTD_REG = MDIO_ALL_PORT_HIGH;
			}
			else if (Copy_u8PortValue == MDIO_ALL_PORT_LOW)
			{
				/* Set PORTD Register to LOW */
				PRIVATE_PORTD_REG = MDIO_ALL_PORT_LOW;
			}
			else
			{
				Local_u8ErrorState = STD_TYPE_NOK;
			}
			break;
		default:
			Local_u8ErrorState = STD_TYPE_NOK;
			break;
		}
	}
	return Local_u8ErrorState;
}

/* Get Pin Value */
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState = STD_TYPE_OK; // Initialize error state to OK

	// Check if the port ID, pin ID are within valid ranges and pointer is not NULL
	if (Copy_u8PortId <= MDIO_PORTD && Copy_u8PinId <= MDIO_Pin_7 && Copy_pu8ReturnedPinValue != POINTER_NULL)
	{
		// Retrieve the value from the correct port
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			*Copy_pu8ReturnedPinValue = GET_BIT(PRIVATE_PINA_REG, Copy_u8PinId); // Get specific pin value from PORTA
			break;
		case MDIO_PORTB:
			*Copy_pu8ReturnedPinValue = GET_BIT(PRIVATE_PINB_REG, Copy_u8PinId); // Get specific pin value from PORTB
			break;
		case MDIO_PORTC:
			*Copy_pu8ReturnedPinValue = GET_BIT(PRIVATE_PINC_REG, Copy_u8PinId); // Get specific pin value from PORTC
			break;
		case MDIO_PORTD:
			*Copy_pu8ReturnedPinValue = GET_BIT(PRIVATE_PIND_REG, Copy_u8PinId); // Get specific pin value from PORTD
			break;
		default:
			Local_u8ErrorState = STD_TYPE_NOK; // Set error state to NOK if port ID is invalid
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPE_NOK; // Set error state to NOK if input parameters are invalid
	}

	return Local_u8ErrorState; // Return the error state
}

/* Get Port Value */
u8 MDIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPE_OK; // Corrected spelling from ErrorSate to ErrorState
	if (Copy_u8PortId <= MDIO_PORTD && Copy_pu8ReturnedPortValue != POINTER_NULL)
	{
		/* Set Pin Value */
		switch (Copy_u8PortId)
		{
		case MDIO_PORTA:
			*Copy_pu8ReturnedPortValue = PRIVATE_PINA_REG;
			break;
		case MDIO_PORTB:
			*Copy_pu8ReturnedPortValue = PRIVATE_PINB_REG;
			break;
		case MDIO_PORTC:
			*Copy_pu8ReturnedPortValue = PRIVATE_PINC_REG;
			break;
		case MDIO_PORTD:
			*Copy_pu8ReturnedPortValue = PRIVATE_PIND_REG;
			break;
		default:
			Local_u8ErrorState = STD_TYPE_NOK;
			break;
		}
	}
	return Local_u8ErrorState;
}
