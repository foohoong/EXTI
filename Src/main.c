/*****************************************************************************
 @Project	: 
 @File 		: main.c
 @Details  	: EXTI on STM32F103RB Nucleo              
 @Author	: Fong FH
 @Hardware	: STM32
 
 --------------------------------------------------------------------------
 @Revision	:
  Ver  	Author    	Date        	Changes
 --------------------------------------------------------------------------
   1.0  Name     XXXX-XX-XX  		Initial Release
   
******************************************************************************/
#include <Common.h>
#include "Hal.h"
#include "IRQ.h"
#include "BSP.h"


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
 Const Local Variables
******************************************************************************/


/*****************************************************************************
 Local Variables
******************************************************************************/
static volatile BOOL		g_bSystemTick = FALSE;
volatile BOOL        user_btn = FALSE;

/*****************************************************************************
 Local function Prototype
******************************************************************************/


/*****************************************************************************
 Callback function Prototype
******************************************************************************/


/*****************************************************************************
 Implementation 
******************************************************************************/
void main( void )
{
	int toggle = 0;
	BSPInit();

    TRACE( "SEP150 Skeleton\r\n" );

	SysTick_Config( SystemCoreClock/10 );  /* Generate interrupt each 100 ms */
                                           /* SystemCoreClock is defined in 'system_stm32f10x.c' */

    for(;;)
    {
        if( FALSE != g_bSystemTick )
        {
            g_bSystemTick = FALSE;
            if (FALSE !=user_btn)
            {       
                toggle = !toggle;
                LED_SET( toggle );	/* Toggle LED every 100ms */
            }        
            else
                LED_OFF();
        }
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
void SysTick_Handler( void )
{
	/* Provide system tick */
    g_bSystemTick = TRUE;
}


/*************************** End of file *************************************/
