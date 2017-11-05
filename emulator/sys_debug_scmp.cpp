// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		debug_scmp.c
//		Purpose:	Debugger Code (System Dependent)
//		Created:	3rd September 2015
//		Author:		Paul Robson (paul@robsons->org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gfx.h"
#include "sys_processor.h"
#include "debugger.h"

static const char* _mnemonics[256] = 
#include "_scmp_mnemonics.h"


#define DBGC_ADDRESS 	(0x0F0)														// Colour scheme.
#define DBGC_DATA 		(0x0FF)														// (Background is in main.c)
#define DBGC_HIGHLIGHT 	(0xFF0)

// *******************************************************************************************************************************
//											This renders the debug screen
// *******************************************************************************************************************************

static const char *labels[] = { "A","E","S","P0","P1","P2","P3","CL","BP","CY", NULL };

void DBGXRender(int *address,int showDisplay) {
	int n = 0;
	char buffer[32],buffer2[4];
	CPUSTATUS *s = CPUGetStatus();
	GFXSetCharacterSize(32,22);
	DBGVerticalLabel(19,0,labels,DBGC_ADDRESS,-1);									// Draw the labels for the register

	#define DN(v,w) GFXNumber(GRID(22,n++),v,16,w,GRIDSIZE,DBGC_DATA,-1)			// Helper macro

	n = 0;
	DN(s->a,2);DN(s->e,2);DN(s->s,2);												// Dump Registers etc.
	DN(s->p0,4);DN(s->p1,4);DN(s->p2,4);DN(s->p3,4);		
	DN((s->s >> 7) & 1,1);DN(address[3],4);DN(s->cycles,4);

	int a = address[1];																// Dump Memory.
	for (int row = 15;row < 22;row++) {
		GFXNumber(GRID(2,row),a,16,4,GRIDSIZE,DBGC_ADDRESS,-1);
		GFXCharacter(GRID(6,row),':',GRIDSIZE,DBGC_HIGHLIGHT,-1);
		for (int col = 0;col < 8;col++) {
			GFXNumber(GRID(7+col*3,row),CPURead(a),16,2,GRIDSIZE,DBGC_DATA,-1);
			a = (a + 1) & 0xFFFF;
		}		
	}
	int p = address[0];																// Dump program code. 
	int opc,opr;
	for (int row = 0;row < 13;row++) {
		int isPC = (p == ((s->p0+1) & 0xFFFF));										// Tests.
		int isBrk = (p == address[3]);
		GFXNumber(GRID(2,row),p,16,4,GRIDSIZE,isPC ? DBGC_HIGHLIGHT:DBGC_ADDRESS,	// Display address / highlight / breakpoint
																	isBrk ? 0xF00 : -1);
		opc = CPURead(p);p = (p + 1) & 0xFFFF;										// Read opcode.
		opr = 0;
		if ((opc & 0x80) != 0) {	
			opr = CPURead(p);p = (p + 1) & 0xFFFF;									// Read operand.
		}
		strcpy(buffer,_mnemonics[opc]);												// Set the mnemonic.
		if (buffer[0] == '\0') sprintf(buffer,"db %02x",opc);						// Make up one if required.

		char *ph = strchr(buffer,'%');												// Insert operand
		if (ph != NULL) {
			sprintf(buffer2,"%02x",opr);
			*ph++ = buffer2[0];
			*ph++ = buffer2[1];
		}
					
		GFXString(GRID(7,row),buffer,GRIDSIZE,isPC ? DBGC_HIGHLIGHT:DBGC_DATA,-1);	// Print the mnemonic
	}

}	