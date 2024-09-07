#ifndef MIDO_PRIVATE_H
#define MIDO_PRIVATE_H



/*Define PORTA Registers*/

#define PRIVATE_PORTA_REG  *((volatile u8 *)0x3B)
#define PRIVATE_DDRA_REG   *((volatile u8 *)0x3A)
#define PRIVATE_PINA_REG   *((volatile const u8 *)0x39)

/*Define PORTB Registers*/
#define PRIVATE_PORTB_REG  *((volatile u8 *)0x38)
#define PRIVATE_DDRB_REG   *((volatile u8 *)0x37)
#define PRIVATE_PINB_REG   *((volatile const u8 *)0x36)

/*Define PORTC Registers*/
#define PRIVATE_PORTC_REG  *((volatile u8 *)0x35)
#define PRIVATE_DDRC_REG   *((volatile u8 *)0x34)
#define PRIVATE_PINC_REG   *((volatile const u8 *)0x33)

/*Define PORTD Registers*/
#define PRIVATE_PORTD_REG  *((volatile u8 *)0x32)
#define PRIVATE_DDRD_REG   *((volatile u8 *)0x31)
#define PRIVATE_PIND_REG   *((volatile const u8 *)0x30)


#endif
