/*
 * Debugger register handling
 *
 * Copyright 1995 Alexandre Julliard
 */

#include <stdio.h>
#include "debugger.h"


SIGCONTEXT *DEBUG_context;



/***********************************************************************
 *           DEBUG_SetRegister
 *
 * Set a register value.
 */
void DEBUG_SetRegister( enum debug_regs reg, int val )
{
    switch(reg)
    {
        case REG_EAX: EAX_reg(DEBUG_context) = val; break;
        case REG_EBX: EBX_reg(DEBUG_context) = val; break;
        case REG_ECX: ECX_reg(DEBUG_context) = val; break;
        case REG_EDX: EDX_reg(DEBUG_context) = val; break;
        case REG_ESI: ESI_reg(DEBUG_context) = val; break;
        case REG_EDI: EDI_reg(DEBUG_context) = val; break;
        case REG_EBP: EBP_reg(DEBUG_context) = val; break;
        case REG_EFL: EFL_reg(DEBUG_context) = val; break;
        case REG_EIP: EIP_reg(DEBUG_context) = val; break;
        case REG_ESP: ESP_reg(DEBUG_context) = val; break;
        case REG_AX:  AX_reg(DEBUG_context)  = val; break;
        case REG_BX:  BX_reg(DEBUG_context)  = val; break;
        case REG_CX:  CX_reg(DEBUG_context)  = val; break;
        case REG_DX:  DX_reg(DEBUG_context)  = val; break;
        case REG_SI:  SI_reg(DEBUG_context)  = val; break;
        case REG_DI:  DI_reg(DEBUG_context)  = val; break;
        case REG_BP:  BP_reg(DEBUG_context)  = val; break;
        case REG_FL:  FL_reg(DEBUG_context)  = val; break;
        case REG_IP:  IP_reg(DEBUG_context)  = val; break;
        case REG_SP:  SP_reg(DEBUG_context)  = val; break;
        case REG_CS:  CS_reg(DEBUG_context)  = val; break;
        case REG_DS:  DS_reg(DEBUG_context)  = val; break;
        case REG_ES:  ES_reg(DEBUG_context)  = val; break;
        case REG_SS:  SS_reg(DEBUG_context)  = val; break;
    }
}


/***********************************************************************
 *           DEBUG_GetRegister
 *
 * Get a register value.
 */
int DEBUG_GetRegister( enum debug_regs reg )
{
    switch(reg)
    {
        case REG_EAX: return EAX_reg(DEBUG_context);
        case REG_EBX: return EBX_reg(DEBUG_context);
        case REG_ECX: return ECX_reg(DEBUG_context);
        case REG_EDX: return EDX_reg(DEBUG_context);
        case REG_ESI: return ESI_reg(DEBUG_context);
        case REG_EDI: return EDI_reg(DEBUG_context);
        case REG_EBP: return EBP_reg(DEBUG_context);
        case REG_EFL: return EFL_reg(DEBUG_context);
        case REG_EIP: return EIP_reg(DEBUG_context);
        case REG_ESP: return ESP_reg(DEBUG_context);
        case REG_AX:  return AX_reg(DEBUG_context);
        case REG_BX:  return BX_reg(DEBUG_context);
        case REG_CX:  return CX_reg(DEBUG_context);
        case REG_DX:  return DX_reg(DEBUG_context);
        case REG_SI:  return SI_reg(DEBUG_context);
        case REG_DI:  return DI_reg(DEBUG_context);
        case REG_BP:  return BP_reg(DEBUG_context);
        case REG_FL:  return FL_reg(DEBUG_context);
        case REG_IP:  return IP_reg(DEBUG_context);
        case REG_SP:  return SP_reg(DEBUG_context);
        case REG_CS:  return CS_reg(DEBUG_context);
        case REG_DS:  return DS_reg(DEBUG_context);
        case REG_ES:  return ES_reg(DEBUG_context);
        case REG_SS:  return SS_reg(DEBUG_context);
    }
    return 0;  /* should not happen */
}



/***********************************************************************
 *           DEBUG_InfoRegisters
 *
 * Display registers information. 
 */
void DEBUG_InfoRegisters(void)
{
    fprintf(stderr,"Register dump:\n");

    /* First get the segment registers out of the way */
    fprintf( stderr," CS:%04x SS:%04x DS:%04x ES:%04x\n",
             CS_reg(DEBUG_context), SS_reg(DEBUG_context),
             DS_reg(DEBUG_context), ES_reg(DEBUG_context) );

    if (dbg_mode == 16)
    {
        fprintf( stderr," IP:%04x SP:%04x BP:%04x FLAGS:%04x\n",
                 IP_reg(DEBUG_context), SP_reg(DEBUG_context),
                 BP_reg(DEBUG_context), FL_reg(DEBUG_context) );
	fprintf( stderr," AX:%04x BX:%04x CX:%04x DX:%04x SI:%04x DI:%04x\n",
                 AX_reg(DEBUG_context), BX_reg(DEBUG_context),
                 CX_reg(DEBUG_context), DX_reg(DEBUG_context),
                 SI_reg(DEBUG_context), DI_reg(DEBUG_context) );
    }
    else  /* 32-bit mode */
    {
        fprintf( stderr, " EIP:%08lx ESP:%08lx EBP:%08lx EFLAGS:%08lx\n", 
                 EIP_reg(DEBUG_context), ESP_reg(DEBUG_context),
                 EBP_reg(DEBUG_context), EFL_reg(DEBUG_context) );
	fprintf( stderr, " EAX:%08lx EBX:%08lx ECX:%08lx EDX:%08lx\n", 
		 EAX_reg(DEBUG_context), EBX_reg(DEBUG_context),
                 ECX_reg(DEBUG_context), EDX_reg(DEBUG_context) );
	fprintf( stderr, " ESI:%08lx EDI:%08lx\n",
                 ESI_reg(DEBUG_context), EDI_reg(DEBUG_context) );
    }
}

