#ifndef TWI_REGISTER_H
#define TWI_REGISTER_H

#define TWDR              *((volatile u8*)0x23)
#define TWAR              *((volatile u8*)0x22)

#define TWSR              *((volatile u8*)0x21)
#define TWBR              *((volatile u8*)0x20)

#define TWCR              *((volatile u8*)0x56)

#endif