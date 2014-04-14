/*
 * c_modstruct.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "classMODREGISTER.h"

// +------------------------------------+
// 		ModRegisterClass: CLASS
// +------------------------------------+

//ModRegisterClass * ModRegisterClass::pthis;

// +------------------------------------+
// 		ModRegisterClass
// +------------------------------------+

ModRegisterClass::ModRegisterClass(int Device) : ModBaseClass()
{
	m_Device = Device;
	memset(&sMODdata, 0, sizeof(sMODdata));

	sprintf(m_DevName,"Dev#%d",Device);
	printf("classMODREGISTER Created: %s\n", m_DevName);
}

// +------------------------------------+
// 		~ModRegisterClass
// +------------------------------------+

ModRegisterClass::~ModRegisterClass()
{
	printf("classMODREGISTER Destroyed: %s\n", m_DevName);
}


// +------------------------------------+
// 		ConfigRegister
// +------------------------------------+

void ModRegisterClass::ConfigRegister( IONewType &iotmp)
{
	if (iotmp.eDev == m_Device)
	{
		printf("device is correct\n");

		if (iotmp.eDir == IN)
			printf("device is input\n");
		else
			printf("device is output\n");
	}
}


// +------------------------------------+
// 		Write_Set
// +------------------------------------+

void ModRegisterClass::Write_Set(IONewType &tmpio)
{
	//printf("MESSAGE: Write Set: DevName %s\n", m_DevName);

	if (tmpio.eDir == OUT)
	{
		sMODdata.outword[tmpio.Word] |= (1 << tmpio.Bit);
	}
	else
	{
		printf("ERROR: not an output\n");
	}
}


// +------------------------------------+
// 		Write_Rst
// +------------------------------------+

void ModRegisterClass::Write_Rst(IONewType &tmpio)
{
	//printf("MESSAGE: Write Rst: DevName %s\n", m_DevName);

	if (tmpio.eDir == OUT)
	{
		sMODdata.outword[tmpio.Word] &= ~(1 << tmpio.Bit);
	}
	else
	{
		printf("ERROR: not an output\n");
	}
}


// +------------------------------------+
// 		ReadValue
// +------------------------------------+

int ModRegisterClass::ReadValue(IONewType &tmpio)
{
	//printf("ERROR: not an output\n");

	if (tmpio.eDir == IN)
	{
		m_datain = sMODdata.inword[tmpio.Word] & (1 << tmpio.Bit);
		return (m_datain);
	}
	else
	{
		m_datain = sMODdata.outword[tmpio.Word] & (1 << tmpio.Bit);
		return (m_datain);
	}
}

// +------------------------------------+
// 		Write_Field
// +------------------------------------+

void ModRegisterClass::Write_Field(IONewType &tmpio, int tmpval)
{
	int mask, store;

	if (tmpio.eDir == OUT)
	{
		store = sMODdata.outword[tmpio.Word];		// copy current register
		mask = ( (1 << tmpio.Width) - 1);			// creates a mask of 0b1111 from 0x10000
		store &= (~(mask << tmpio.Bit));			// shifts mask to bit and inverts
		store |= ((tmpval & mask) << tmpio.Bit);	// aligns tmpval with mask and OR's it in

		sMODdata.outword[tmpio.Word] = store;		// copy back to output register

	}
	else
		printf("ERROR: not an output\n");

}


// +------------------------------------+
// 		Read_Field
// +------------------------------------+

void ModRegisterClass::Read_Field(IONewType &tmpio, int tmpval)
{
	if (tmpio.eDir == IN)
	{


	}
	else
		printf("ERROR: not an input\n");
}



// +------------------------------------+
// 		get_iomap
// +------------------------------------+


MODdataType ModRegisterClass::get_iomap()
{
	//return this->sMODdata;
	return sMODdata;
}



