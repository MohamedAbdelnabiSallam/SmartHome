/**************************************/
/* Description : TIM1 program file    */
/* Author      : Ahmed Saeed          */
/* Version     : 0.1v                 */
/* Date        : 7 Jan 2023           */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types1.h"
#include "BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf  TIM1_pfOvfCallBack;
pf  TIM1_pfCmpACallBack;
pf  TIM1_pfCmpBCallBack;
pf  TIM1_pfIcuCallBack;


void TIM1_voidInit(void)
{
	/*select timer mode  */
#if  TIM1_MODE ==  TIM1_NORMAL 
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_CTC_TOP_TO_OCR1A   
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_CTC_TOP_TO_ICR1  
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_F_PWM_8BIT
    SET_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_F_PWM_9BIT
    CLR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_F_PWM_10BIT
    SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_F_PWM_TO_ICR1
    CLR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_F_PWM_TO_OCR1A
    SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_PH_PWM_8BIT
    SET_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_PH_PWM_9BIT
    CLR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_PH_PWM_10BIT
    SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_PH_PWM_TO_ICR1
    CLR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
#elif TIM1_MODE ==  TIM1_PH_PWM_TO_OCR1A
    SET_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
#else
	CLR_BIT(TCCR1A , 0);
	CLR_BIT(TCCR1A , 1);
	CLR_BIT(TCCR1B , 3);
	CLR_BIT(TCCR1B , 4);
#endif 


    /*select wave form  in case of compare A  */
#if TIM1_OUTFORM_comA == TIM1_TOGL_OC1A 
    SET_BIT(TCCR1A , 6);
	CLR_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_CLR_OC1A 
    CLR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_SET_OC1A 
    SET_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_F_NON_INVERT_OC1A 
    CLR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_F_INVERT_OC1A 
    SET_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_PH_NON_INVERT_OC1A 
    CLR_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
#elif TIM1_OUTFORM_comA == TIM1_PH_INVERT_OC1A 
    SET_BIT(TCCR1A , 6);
	SET_BIT(TCCR1A , 7);
	
#else
	CLR_BIT(TCCR1A , 6);
	CLR_BIT(TCCR1A , 7);
#endif
	
	
    /*select wave form  in case of compare B  */
#if TIM1_OUTFORM_comB == TIM1_TOGL_OC1B 
    SET_BIT(TCCR1A , 4);
	CLR_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB== TIM1_CLR_OC1B 
    CLR_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB == TIM1_SET_OC1B 
    SET_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB == TIM1_F_NON_INVERT_OC1B 
    CLR_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB == TIM1_F_INVERT_OC1B 
    SET_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB == TIM1_PH_NON_INVERT_OC1B 
    CLR_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
#elif TIM1_OUTFORM_comB == TIM1_PH_INVERT_OC1B 
    SET_BIT(TCCR1A , 4);
	SET_BIT(TCCR1A , 5);
	
#else
	CLR_BIT(TCCR1A , 4);
	CLR_BIT(TCCR1A , 5);

#endif
  /*Disable timer*/
  TCCR1B &= 0b11111000;
  /*Disable Int OVF-CMPA,B ICU*/
  CLR_BIT(TIMSK , 2 );
  CLR_BIT(TIMSK , 3);
  CLR_BIT(TIMSK , 4 );
  CLR_BIT(TIMSK , 5);
  /*Clear Int OVF-CMP flags*/
  SET_BIT(TIFR , 2 );
  SET_BIT(TIFR , 3 );
  SET_BIT(TIFR , 4 );
  SET_BIT(TIFR , 5 );
  
  /*Clear TCNT,OCE1A,B,ICR*/
  OCR1AL = 0 ;
  OCR1AH = 0 ;
  OCR1BL = 0 ;
  OCR1BH = 0 ;
  TCNT1L = 0 ;
  TCNT1H = 0 ;
  ICR1L  = 0 ;
  ICR1H  = 0 ;
  
}
void TIM1_voidEnable(u8 u8PrescalValCpy)
{
	TCCR1B &= 0b11111000;
	TCCR1B |= u8PrescalValCpy & 0x07 ;// 0b00000111
	
}
void TIM1_voidDisable(void)
{
	TCCR1B &= 0b11111000;
	
}
void TIM1_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK , 2 );
	
}
void TIM1_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , 2 );
	
}
void TIM1_voidEnableCmpAInt(void)
{
	SET_BIT(TIMSK , 4 );
	
}
void TIM1_voidDisableCmpAInt(void)
{
	CLR_BIT(TIMSK , 4 );
	
}
void TIM1_voidEnableCmpBInt(void)
{
	SET_BIT(TIMSK , 3 );
	
}
void TIM1_voidDisableCmpBInt(void)
{
	CLR_BIT(TIMSK , 3);
	
}
void TIM1_voidEnableIcu(void)
{
	SET_BIT(TIMSK , 5 );
}
void TIM1_voidDisableIcu(void)
{
	CLR_BIT(TIMSK , 5);
}

void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy)
{
	TIM1_pfOvfCallBack = pfOvfCalbckCpy;
}
void TIM1_voidSetCallbackCompAInt(pf pfCompACalbckCpy)
{
	TIM1_pfCmpACallBack = pfCompACalbckCpy;
}
void TIM1_voidSetCallbackCompBInt(pf pfCompBCalbckCpy)
{
	TIM1_pfCmpBCallBack = pfCompBCalbckCpy;
}
void TIM1_voidSetCallbackIcu(pf pfIcuCalbckCpy)
{
	TIM1_pfIcuCallBack = pfIcuCalbckCpy;
}
void TIM1_voidSetTimerValue(u16 u16TimValCpy) //TCNT
{
	TCNT1L =(u8) u16TimValCpy;
	TCNT1H =(u8) (u16TimValCpy>>8);
	//TCNT1=u16TimValCpy
}
void TIM1_voidSetCmpARegValue(u16 u16CmpAValCpy)
{
	OCR1AL= (u8)u16CmpAValCpy;
	OCR1AH= (u8)(u16CmpAValCpy>>8);
	
}
void TIM1_voidSetCmpBRegValue(u16 u16CmpBValCpy)
{
	OCR1BL= (u8)u16CmpBValCpy;
	OCR1BH= (u8)(u16CmpBValCpy>>8);
	
}
void TIM1_voidSetIcuRegValue(u16 u16IcuValCpy)
{
	ICR1=u16IcuValCpy;

}
u16 TIM1_u8ReadTimerValue(void)
{
	u16 u16TcntValueLoc;
	u16TcntValueLoc   = TCNT1H;
	u16TcntValueLoc   = (u16TcntValueLoc<<8);
	u16TcntValueLoc |= TCNT1L;
	return u16TcntValueLoc;
}
/* ISR for overflow*/
void __vector_9(void) __attribute__ ((signal,used));
void __vector_9 (void)
{
	TIM1_pfOvfCallBack();
	
}
/* ISR for compaA*/

void __vector_7 (void) __attribute__ ((signal,used));
void __vector_7 (void)
{
	TIM1_pfCmpACallBack();
}
/* ISR for compaB*/

void __vector_8 (void) __attribute__ ((signal,used));
void __vector_8 (void)
{
	TIM1_pfCmpBCallBack();
}
/* ISR for ICU*/

void __vector_6 (void) __attribute__ ((signal,used));
void __vector_6 (void)
{
	TIM1_pfIcuCallBack();
}



/*ICU*/


u16 TIM1_u16GetIcuValue(void)
{
	return ICR1;
}
void ICU_voidRisingEdge(void)
 {
	SET_BIT(TCCR1B , 6);
 }
 
 void ICU_voidFallenEdge(void)
 {
	CLR_BIT(TCCR1B , 6);
 }
 

