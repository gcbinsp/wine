#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "msdos.h"
#include "ldt.h"
#include "wine.h"
#include "miscemu.h"
#include "drive.h"
#include "stddebug.h"
/* #define DEBUG_INT */
#include "debug.h"

/**********************************************************************
 *	    INT_Int26Handler
 *
 * Handler for int 26h (absolute disk read).
 */
void INT_Int26Handler( SIGCONTEXT context )
{
    BYTE *dataptr = PTR_SEG_OFF_TO_LIN( DS_reg(&context), BX_reg(&context) );
    DWORD begin, length;

    if (!DRIVE_IsValid(AL_reg(&context)))
    {
        SET_CFLAG(&context);
        AX_reg(&context) = 0x0101;        /* unknown unit */
        return;
    }

    if (CX_reg(&context) == 0xffff)
    {
        begin   = *(DWORD *)dataptr;
        length  = *(WORD *)(dataptr + 4);
        dataptr = (BYTE *)PTR_SEG_TO_LIN( *(SEGPTR *)(dataptr + 6) );
    }
    else
    {
        begin = DX_reg(&context);
        length = CX_reg(&context);
    }
		
    dprintf_int( stdnimp,"int26: abs diskwrite, drive %d, sector %ld, "
                 "count %ld, buffer %d\n",
                 AL_reg(&context), begin, length, (int) dataptr );

    RESET_CFLAG(&context);
}
