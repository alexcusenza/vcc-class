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
// 		classMODREGISTER
// +------------------------------------+

classMODREGISTER::classMODREGISTER(
        int Device) :
        classMODBASE()
{
    m_Device = Device;
    memset(&sMODdata, 0, sizeof(sMODdata));

    sprintf(m_DevName,"Dev#%d",Device);
    printf("classMODREGISTER Created: %s\n", m_DevName);
}

// +------------------------------------+
// 		~classMODREGISTER
// +------------------------------------+

classMODREGISTER::~classMODREGISTER()
{
    printf("classMODREGISTER Destroyed: %s\n", m_DevName);
}


// +------------------------------------+
// 		ConfigRegister
// +------------------------------------+

void classMODREGISTER::ConfigRegister( IODefType &iotmp)
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
//      WriteValue
// +------------------------------------+
void classMODREGISTER::WriteValue(IODefType & tmpio, eSetRstType eSR)
{
    if (tmpio.eDir == OUT)
    {
        if (eSR == SET)
        {
            sMODdata.outword[tmpio.Word] |= (1 << tmpio.Bit);

        }
        else if (eSR == RST)
        {
            sMODdata.outword[tmpio.Word] &= ~(1 << tmpio.Bit);
        }
    }
    else
        printf("ERROR: not an output\n");
}

// +------------------------------------+
// 		ReadValue
// +------------------------------------+

int classMODREGISTER::ReadValue(IODefType &tmpio)
{
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

void classMODREGISTER::Write_Field(IODefType &tmpio, int tmpval)
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

void classMODREGISTER::Read_Field(IODefType &tmpio, int tmpval)
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


MODdataType classMODREGISTER::get_iomap()
{
    //return this->sMODdata;
    return sMODdata;
}



