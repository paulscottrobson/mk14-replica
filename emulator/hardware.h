// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Interface (header)
//		Date:		1st October 2017
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H
	
void HWIReset(void);

void HWIWriteSegment(BYTE8 digit,BYTE8 data);
BYTE8 HWIReadSegment(BYTE8 digit);
BYTE8 HWIReadKeyRow(BYTE8 row);

int HWIProcessKey(int key,int runMode);
void  HWIEndFrame(void);

#endif
