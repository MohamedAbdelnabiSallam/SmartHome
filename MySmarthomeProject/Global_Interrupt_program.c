#include "STD_TYPES1.h"
#include "BIT_MATH.h"
#include "Global_Interrupt_register.h"
#include "Global_Interrupt_interface.h"

void Global_Interrupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void Global_Interrupt_Disable(void)
{
	CLR_BIT(SREG,I);
}
