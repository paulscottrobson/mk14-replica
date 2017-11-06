// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.cpp
//		Purpose:	Processor Emulation.
//		Created:	26th October 2015
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifdef WINDOWS
#endif
#include <stdio.h>
#include "sys_processor.h"
#include "hardware.h"

// *******************************************************************************************************************************
//														Main Memory/CPU
// *******************************************************************************************************************************

static BYTE8 ramMemory[RAMSIZE];													// RAM memory

static BYTE8 a,e,status,cyl,overflow,mbr;
static WORD16 p0,p1,p2,p3,t16,mar;

static BYTE8 interruptRequest;
static WORD16 cycles;
static WORD16 delaycyclesfour;

// *******************************************************************************************************************************
//													Memory read and write macros.
// *******************************************************************************************************************************

#define pcread() 	mbr = ramMemory[(mar) & MEMORYMASK]

static void write() {
 	if ((mar & 0xF00) == 0xF00) {
		ramMemory[(mar) & MEMORYMASK] = mbr;
		return;
	}
 	if ((mar & 0xD00) == 0xD00) {
 		HWIWriteSegment(mar & 0xFF,mbr);
 	}
}

static void read() {
	mbr = ramMemory[(mar) & MEMORYMASK];
	if ((mar & 0xF00) == 0xD00) {
		mbr = HWIReadKeyRow(mar & 0x0F);
	}
}

// *******************************************************************************************************************************
//														I/O Port connections
// *******************************************************************************************************************************

#define io_sensea() 	(0)
#define io_senseb()	(0)
#define io_flags(d)	{}
#define io_sin() 		(0)
#define io_sout(b) 	{}

// *******************************************************************************************************************************
//													  Port interfaces
// *******************************************************************************************************************************

void CPUReset(void) {
	a = e = p0 = p1 = p2 = p3 = cyl = status = overflow = 0;
	cycles = 0;delaycyclesfour = 0;
	interruptRequest = 0;
	HWIReset();
}

// *******************************************************************************************************************************
//													 Arithmetic
// *******************************************************************************************************************************

#include "_scmp_support.h"

// *******************************************************************************************************************************
//												    Request an interrupt
// *******************************************************************************************************************************

void CPUInterruptRequest(void) {
	interruptRequest = 1;
}

// *******************************************************************************************************************************
//											Execute a single instruction phase
// *******************************************************************************************************************************

#include <stdlib.h>
#include <stdio.h>

BYTE8 CPUExecuteInstruction(void) {

	if (delaycyclesfour != 0) {														// DLY in progress
		WORD16 remCycles = CYCLES_PER_FRAME - cycles;								// Cycles left this frame
		if (remCycles/4 < delaycyclesfour) {										// Not enough cycles
			delaycyclesfour = delaycyclesfour - remCycles / 4;
			cycles = 0;
			return FRAME_RATE;
		} else {																	// enough this time.
			cycles = cycles + delaycyclesfour * 4;
			delaycyclesfour = 0;
		}
	}

	fetch();
	pcread();
	switch(mbr) {																	// Do the selected opcode and phase.
		#include "_scmp_case.h"
	}

	if (cycles < CYCLES_PER_FRAME) return 0;										// Frame in progress, return 0.
	cycles -= CYCLES_PER_FRAME;														// Adjust cycle counter
	HWIEndFrame();																	// Hardware stuff.
	return FRAME_RATE;																// Return the frame rate for sync speed.
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *******************************************************************************************************************************
//										 Get the step over breakpoint value
// *******************************************************************************************************************************

WORD16 CPUGetStepOverBreakpoint(void) {
	BYTE8 opcode = CPURead(p0+1);													// Read opcode.
	if ((opcode & 0xFC) == 0x3C) return ((p0+1) & 0xFFFF);							// XPPC Px
	return 0xFFFF;
}

// *******************************************************************************************************************************
//										Run continuously till breakpoints / Halt.
// *******************************************************************************************************************************

BYTE8 CPUExecute(WORD16 break1,WORD16 break2) {
	BYTE8 rate = 0;
	while(1) {
		rate = CPUExecuteInstruction();												// Execute one instruction phase.
		if (rate != 0) {															// If end of frame, return rate.
			return rate;													
		}
		if (p0+1 == break1 || p0+1 == break2) return 0;
	} 																				// Until hit a breakpoint or HLT.
}

// *******************************************************************************************************************************
//												Load a binary file into RAM
// *******************************************************************************************************************************

void CPULoadBinary(char *fileName) {
	FILE *f = fopen(fileName,"rb");
	fread(ramMemory,RAMSIZE,1,f);
	fclose(f);
}

// *******************************************************************************************************************************
//												Gets a pointer to RAM memory
// *******************************************************************************************************************************
	
BYTE8 CPURead(WORD16 address) {
	mar = address;read();return mbr;
}

// *******************************************************************************************************************************
//											Retrieve a snapshot of the processor
// *******************************************************************************************************************************

static CPUSTATUS s;																	// Status area

CPUSTATUS *CPUGetStatus(void) {
	correctStatusRegister();
	s.a = a;s.e = e;s.s = status;
	s.pc = p0;s.p0 = p0;s.p1 = p1;s.p2 = p2;s.p3 = p3;
	s.cycles = cycles;																// Number of cycles.
	return &s;
}
#endif
