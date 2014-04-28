/*
 * classSIGNALHMI.cpp
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
		m_HMI(tHMI),
		m_oneshot(false)
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
	if (mp_Port->get_iomap() && !m_oneshot)
		m_oneshot = true;
	else
		m_oneshot = false;

}
