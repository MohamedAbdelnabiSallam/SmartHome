/**************************************/
/* Description : TIM1 interface file  */
/* Author      : Ahmed Saeed          */
/* Version     : 0.1v                 */
/* Date        : 7 Jan 2023           */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef  TIM1_H
#define  TIM1_H

void TIM1_voidInit(void);
void TIM1_voidEnable(u8 u8PrescalValCpy);
void TIM1_voidDisable(void);
void TIM1_voidEnableOvfInt(void);
void TIM1_voidDisableOvfInt(void);
void TIM1_voidEnableCmpAInt(void);
void TIM1_voidDisableCmpAInt(void);
void TIM1_voidEnableCmpBInt(void);
void TIM1_voidDisableCmpBInt(void);
void TIM1_voidEnableIcu(void);
void TIM1_voidDisableIcu(void);
//void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy);
//void TIM1_voidSetCallbackCompAInt(pf pfCompACalbckCpy);
//void TIM1_voidSetCallbackCompBInt(pf pfCompBCalbckCpy);
//void TIM1_voidSetCallbackIcu(pf pfIcuCalbckCpy);
void TIM1_voidSetTimerValue(u16 u16TimValCpy); //TCNT1
void TIM1_voidSetCmpARegValue(u16 u16CmpAValCpy); //OCR1A
void TIM1_voidSetCmpBRegValue(u16 u16CmpBValCpy); //OCR1B
void TIM1_voidSetIcuRegValue(u16 u16IcuValCpy);   //ICR1
u16 TIM1_u8ReadTimerValue(void);   //TCNT1
u16 TIM1_u16GetIcuValue (void);


void ICU_voidRisingEdge(void);
void ICU_voidFallenEdge(void);
#endif

