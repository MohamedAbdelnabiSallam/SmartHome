/*****************************************************************/
/* Author  : MO                                              */
/* SWC     : EEPROM                                              */
/* Version : 1.0                                                 */
/* Date    : 28 Dec 2023                                         */
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "MTWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


void EEPROM_vRead(u8 cpy_u8LocationAddress,u8 *cpy_pu8Data)
{
	//start condition
	TWI_enStartCondition();

	//send slave addreess with write
	TWI_enSetSlaveAddressWithWrite(SLAVE_ADDRESS);

	//send memory location
	TWI_enMasterWriteData(cpy_u8LocationAddress);

	//REPEAT START TO CHANGE WRITE OPERATION TO READ OPERATION
	TWI_enRepeateStart();
	TWI_enSetSlaveAddressWithRead(SLAVE_ADDRESS);
	//MASTER RECIEVE DATA
	TWI_enMasterReadData(cpy_pu8Data);

	//STOP
	TWI_vStopCondition();
}

void EEPROM_vWrite(u8 cpy_u8LocationAddress, u8 cpy_pu8Data)
{
	//start condition
	TWI_enStartCondition();

	//send slave addreess with write
	TWI_enSetSlaveAddressWithWrite(SLAVE_ADDRESS);
	//send memory location
	TWI_enMasterWriteData(cpy_u8LocationAddress);
	//MASTER SEN DATA
	TWI_enMasterWriteData(cpy_pu8Data);

	//stop condition
	TWI_vStopCondition();

	_delay_ms(10);
}


void EEPROM_vWritePage(u8 cpy_u8LocationAddress,u8 *cpy_pu8Data,u8 length)
{
	u8 i;
	//start condition
	TWI_enStartCondition();

	//send slave addreess with write
	TWI_enSetSlaveAddressWithWrite(SLAVE_ADDRESS);
	//send memory location
	TWI_enMasterWriteData(cpy_u8LocationAddress);

	for(i=0;i<length;i++)
	{
		//MASTER SEN DATA
			TWI_enMasterWriteData(cpy_pu8Data[i]);
			_delay_ms(10);
	}

	//stop condition
	TWI_vStopCondition();


}

