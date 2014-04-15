/*
 * classHMICONTRO.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "classHMICONTROL.h"


// +------------------------------------+
// 		classHMICONTROL
// +------------------------------------+

classHMICONTROL::classHMICONTROL(classMODREGISTER & tmpPort):
			m_Port(tmpPort)
{

	printf("classHMICONTROL Created: \n");

}


// +------------------------------------+
// 		~classHMICONTROL
// +------------------------------------+

classHMICONTROL::~classHMICONTROL()
{

	printf("classHMICONTROL Destroyed: \n");

}


// +------------------------------------+
// 		classHMICONTROL
// +------------------------------------+

void classHMICONTROL::checkstate()
{
	//m_Port.

}
