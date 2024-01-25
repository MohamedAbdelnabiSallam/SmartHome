/*
 * MTWI_interface.h
 *
 *  Created on: Dec 27, 2023
 *      Author:MO
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

typedef enum{
	NO_ERROR,
	START_CONDTITION_ERR,
	REPEAT_START_ERR,
	SLA_W_NOACK_ERR,
	SLA_R_NOACK_ERR,
	MASTER_SEND_DATA_ERR,
	MASTER_RECEIVE_DATA_ERR,
	MAX_ERR,

}TWI_ErrorState_t;



void TWI_vMasterInit(void);
void TWI_vSlaveInit(void);

TWI_ErrorState_t TWI_enStartCondition(void);
TWI_ErrorState_t TWI_enRepeateStart(void);
TWI_ErrorState_t TWI_enSetSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorState_t TWI_enSetSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
TWI_ErrorState_t TWI_enMasterWriteData(u8 Copy_u8Data);
TWI_ErrorState_t TWI_enMasterReadData(u8 *Copy_u8Data);
void TWI_vStopCondition(void);





#endif /* MTWI_INTERFACE_H_ */
