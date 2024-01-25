/*****************************************************************/
/* Author  : Hamo                                                */
/* SWC     : EEPROM                                              */
/* Version : 1.0                                                 */
/* Date    : 28 Dec 2023                                         */
/*****************************************************************/
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_vRead(u8 cpy_u8LocationAddress,u8 *cpy_pu8Data);
void EEPROM_vWrite(u8 cpy_u8LocationAddress,u8 cpy_pu8Data);


#endif
