/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Tawfik Tamer Ibrahim
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

#include "GIE_interface.h"
#include "GIE_register.h"

/*
 * Breif : This Function used to enable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_Enable (void)
{
	SET_BIT (SREG , SREG_I) ;
}
/*
 * Breif : This Function used to disable General Interrupt Enable (GIE)
 * Parameters : Nothing
 * return : Nothing
*/
void GIE_Disable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}
