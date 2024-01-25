/**************************************/
/* Description : TIM1 private file    */
/* Author      : Ahmed Saeed          */
/* Version     : 0.1v                 */
/* Date        : 7 Jan 2023           */
/* History     : 0.1v initial creation*/
/**************************************/

#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H

/* MODE Configuration*/

#define TIM1_NORMAL                  0
#define TIM1_PH_PWM_8BIT             1
#define TIM1_PH_PWM_9BIT             2
#define TIM1_PH_PWM_10BIT            3
#define TIM1_CTC_TOP_TO_OCR1A        4
#define TIM1_F_PWM_8BIT              5
#define TIM1_F_PWM_9BIT              6
#define TIM1_F_PWM_10BIT             7
#define TIM1_PH_PWM_TO_ICR1          10
#define TIM1_PH_PWM_TO_OCR1A         11
#define TIM1_CTC_TOP_TO_ICR1         12
#define TIM1_F_PWM_TO_ICR1           14
#define TIM1_F_PWM_TO_OCR1A          15

/* waveform Configuration*/

#define  TIM1_TOGL_OC1A              0
#define  TIM1_CLR_OC1A               1
#define  TIM1_SET_OC1A               2
#define  TIM1_F_NON_INVERT_OC1A      3
#define  TIM1_F_INVERT_OC1A          4
#define  TIM1_PH_NON_INVERT_OC1A     5
#define  TIM1_PH_INVERT_OC1A         6
#define  TIM1_TOGL_OC1B              7
#define  TIM1_CLR_OC1B               8
#define  TIM1_SET_OC1B               9
#define  TIM1_F_NON_INVERT_OC1B      10
#define  TIM1_F_INVERT_OC1B          11
#define  TIM1_PH_NON_INVERT_OC1B     12
#define  TIM1_PH_INVERT_OC1B         13

 



#define TIMSK   *((volatile u8 *) 0x59 )
#define TIFR    *((volatile u8 *) 0x58 )

#define TCNT1H   *((volatile u8 *) 0x4D)
#define TCNT1L   *((volatile u8 *) 0x4C)

#define OCR1AH   *((volatile u8 *) 0x4B)
#define OCR1AL   *((volatile u8 *) 0x4A)

#define OCR1BH   *((volatile u8 *) 0x49)
#define OCR1BL   *((volatile u8 *) 0x48)

#define ICR1H    *((volatile u8 *) 0x47)
#define ICR1L    *((volatile u8 *) 0x46)

#define TCCR1A   *((volatile u8 *) 0x4F)
#define TCCR1B   *((volatile u8 *) 0x4E)




#define TCNT1		    	*((volatile u16*)0x4C)
#define OCR1A		    	*((volatile u16*)0x4A)
#define OCR1B		    	*((volatile u16*)0x48)
#define ICR1		    	*((volatile u16*)0x46)


#endif

