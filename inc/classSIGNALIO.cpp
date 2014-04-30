/*
 * classSIGNALIO.cpp
 *
 *  Created on: Apr 26, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "classSIGNALIO.h"


// +------------------------------------+
// 		classSIGNALIO
// +------------------------------------+

classSIGNALIO::classSIGNALIO(
		classMODCONTROL * tClassptr,
		IODefType & tIO):
		mp_Port(tClassptr),
		m_IO(tIO)
{

	printf("classSIGNALIO Created: \n");

}


// +------------------------------------+
// 		~classSIGNALIO
// +------------------------------------+

classSIGNALIO::~classSIGNALIO()
{

	printf("classSIGNALIO Destroyed: \n");

}


// +------------------------------------+
// 		write_set()
// +------------------------------------+

void classSIGNALIO::write_set()
{
	mp_Port->Write_Set(m_IO);
}


// +------------------------------------+
// 		write_rst()
// +------------------------------------+

void classSIGNALIO::write_rst()
{
	mp_Port->Write_Rst(m_IO);

}


void classSIGNALIO::write_field(int tval)
{
	mp_Port->Write_Field(m_IO, tval);

}

// +------------------------------------+
// 		read()
// +------------------------------------+
void classSIGNALIO::readvalue()
{
	mp_Port->ReadValue(m_IO);
}




