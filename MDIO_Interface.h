#ifndef MIDO_INTERFACE_H
#define MIDO_INTERFACE_H

/*Define Port ID*/
#define MDIO_PORTA 	0
#define MDIO_PORTB 	1
#define MDIO_PORTC 	2
#define MDIO_PORTD  3

/*Define Pin ID*/
#define MDIO_Pin_0 	0
#define MDIO_Pin_1 	1
#define MDIO_Pin_2 	2
#define MDIO_Pin_3  3
#define MDIO_Pin_4 	4
#define MDIO_Pin_5 	5
#define MDIO_Pin_6 	6
#define MDIO_Pin_7  7

/* Define Pin Directions */
#define MDIO_OUTPUT           0
#define MDIO_INPUT_FLOATING   1
#define MDIO_INPUT_PULLED_UP  2

/*Define Port Direction*/
#define MDIO_ALL_PORT_OUTPUT 0xFF
#define MDIO_ALL_PORT_INPUT 0x00
/*Define HIGH LOW*/
#define MDIO_HIGH 1
#define MDIO_LOW  0
/*Define All PORT HIGH LOW*/
#define MDIO_ALL_PORT_HIGH 0xFF
#define MDIO_ALL_PORT_LOW 0X00

/* Functions Prototype */
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirec);
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirec);
u8 MDIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
u8 MDIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);
u8 MDIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);

#endif
