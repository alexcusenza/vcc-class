/*
 * classHMICONTRO.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "classSIGNALHMI.h"


// +------------------------------------+
// 		classSIGNALHMI
// +------------------------------------+

classSIGNALHMI::classSIGNALHMI(
		classMODCONTROL * tPort,
		HMIType & tHMI):
		mp_Port(tPort),
		m_HMI(tHMI)
{

	printf("classSIGNALHMI Created: \n");


}


// +------------------------------------+
// 		~classSIGNALHMI
// +------------------------------------+

classSIGNALHMI::~classSIGNALHMI()
{

	printf("classSIGNALHMI Destroyed: \n");

}


// +------------------------------------+
// 		checkstate()
// +------------------------------------+

void classSIGNALHMI::checkstate()
{
	//mp_Port->sMODdata.inword[m_HMI.Word];
	mp_Port->get_iomap();

}
