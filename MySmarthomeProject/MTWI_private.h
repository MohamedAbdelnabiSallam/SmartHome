/*
 * MTWI_private.h
 *
 *  Created on: Dec 27, 2023
 *      Author: hp
 */

#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

#define TWBR				*((volatile u8*)0x20)
#define TWCR                *((volatile u8*)0x56)
#define TWCR_TWINT			7
#define TWCR_TWEA			6
#define TWCR_TWSTA			5
#define TWCR_TWSTO			4
#define TWCR_TWEN			2

#define TWSR                *((volatile u8*)0x21)
#define TWSR_TWPS0			0
#define TWSR_TWPS1			1

#define TWDR                *((volatile u8*)0x23)
#define TWDR_TWD0			0

#define TWAR                *((volatile u8*)0x22)



#define START_CONDITION					0x08
#define REPEATE_START_CONDITION			0x10
#define SLA_WITH_W_NOAK					0x20
#define SLA_WITH_R_NOAK					0x38
#define MASTER_SEND_DATA_NOAK			0x30
#define MASTER_RECEIVE_DATA_NOAK		0x58


#endif /* MTWI_PRIVATE_H_ */
