/*****************************************************************************
 @Project	: 
 @File 		: BSP.c
 @Details  	:
 @Author	: 
 @Hardware	: 
 
 --------------------------------------------------------------------------
 @Revision	:
  Ver  	Author    	Date        	Changes
 --------------------------------------------------------------------------
   1.0  Name     XXXX-XX-XX  		Initial Release
   
******************************************************************************/
#include <Common.h>
#include "BSP.h"
#include "IRQ.h"


/*****************************************************************************
 Define
******************************************************************************/


/*****************************************************************************
 Type definition
******************************************************************************/


/*****************************************************************************
 Global Variables
******************************************************************************/
extern BOOL user_btn;

/*****************************************************************************
 Local Variables
******************************************************************************/


void IRQInit( void )
{
    EXTI -> IMR |= EXTI_IMR_MR13;       // mask register
    EXTI -> FTSR |= EXTI_FTSR_TR13;     // enable falling edge trigger  
    AFIO -> EXTICR[3] &= AFIO_EXTICR4_EXTI13; 
    AFIO -> EXTICR[3] |= AFIO_EXTICR4_EXTI13_PC;   // route to Port C intr
  
    NVIC_EnableIRQ (EXTI15_10_IRQn);
}


/*****************************************************************************
 Implementation
******************************************************************************/
void EXTI0_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI1_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI2_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI3_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI4_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI9_5_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
}


void EXTI15_10_IRQHandler( void )
{
	uint32_t irqStatus = EXTI->PR;
    
    if( 0 != (irqStatus & EXTI_PR_PR13) )
    {       
        user_btn = !user_btn;    
        TRACE( "intr: btn=%i\r\n", user_btn );   
        EXTI->PR = EXTI_PR_PR13;
    }
}



/*****************************************************************************
 Callback functions
******************************************************************************/


/*****************************************************************************
 Local functions
******************************************************************************/


/*****************************************************************************
 Interrupt functions
******************************************************************************/






















