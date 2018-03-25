/*****************************************************************************
 @Project	: 
 @File 		: Hal.c
 @Details  	: All Ports and peripherals configuration                    
 @Author	: 
 @Hardware	: 
 
 --------------------------------------------------------------------------
 @Revision	:
  Ver  	Author    	Date        	Changes
 --------------------------------------------------------------------------
   1.0  Name     XXXX-XX-XX  		Initial Release
   
******************************************************************************/
#include <Common.h>
#include "Hal.h"


/*****************************************************************************
 Define
******************************************************************************/

/*****************************************************************************
 Type definition
******************************************************************************/


/*****************************************************************************
 Global Variables
******************************************************************************/


/*****************************************************************************
 Local Variables
******************************************************************************/


/*****************************************************************************
 Implementation
******************************************************************************/
void PortInit( void )
{
	   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN |        // enable clock for Alt Function
                    RCC_APB2ENR_IOPAEN |        // enable clock for GPIOA
                    RCC_APB2ENR_IOPBEN |        // enable clock for GPIOB                    
                    RCC_APB2ENR_IOPCEN |        // enable clock for GPIOC
                    RCC_APB2ENR_TIM1EN;         // enable clock for Timer 


	GPIOA->CRL &= ~GPIO_CRL_CNF5;
	GPIOA->CRL |= GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1; /* LED PA5 */

     // set GPIO Config & Mode for PC13 (user button)
    GPIOC->CRH &= ~GPIO_CRH_MODE13; // set mode=00(input)

    //GPIOC->CRH &= ~GPIO_CRH_CNF13; 
    GPIOC->CRH &= ~GPIO_CRH_CNF13_0; // set CNF13[0] to 0
    GPIOC->CRH |= GPIO_CRH_CNF13_1; // set CNF13[1] to 1
}


























