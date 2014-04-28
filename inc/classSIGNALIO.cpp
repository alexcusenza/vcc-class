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
		IONewType & tIO):
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
// 		checkstate()
// +------------------------------------+

void classSIGNALIO::checkstate()
{
	//mp_Port->sMODdata.inword[m_HMI.Word];
	mp_Port->get_iomap();
	mp_Port->ReadValue(m_IO);

}



