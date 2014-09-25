/*
 * classVEHMGR.cpp
 *
 *  Created on: May 3, 2014
 *      Author: acusenza
 */

#include <stdio.h>
#include "classVEHMGR.h"
#include "../inc/defsGLOBAL.h"
#include "../inc/defsIOTYPE.h"
#include "../inc/defsHMITYPE.h"


// +------------------------------------+
//		classVEHMGR()
// +------------------------------------+

classVEHMGR::classVEHMGR()
{
	printf("classVEHMGR constructor\n");

	cpMODdev[PLC] = new classMODCONTROL(PLC);
	cpMODdev[SICK0] = new classMODCONTROL(SICK0);
	cpMODhmi = new classMODCONTROL(HMI);

	//cpHMIsig[ehAutoStart] = new classSIGNALHMI(cpMODhmi, hAutoStart);
	//cpHMIsig[ehDestination] = new classSIGNALHMI(cpMODhmi, hDestination);

	pioESTOP = new classSIGNALIO(cpMODdev[PLC], ioESTOP);
	pioSTART = new classSIGNALIO(cpMODdev[PLC], ioSTART);
	pioSICKBUMPER = new classSIGNALIO(cpMODdev[SICK0], ioSICKBUMPER);

	phAutoStart = new classSIGNALHMI(cpMODhmi, hAutoStart);
	phDestination = new classSIGNALHMI(cpMODhmi, hDestination);
}


// +------------------------------------+
//		~classVEHMGR()
// +------------------------------------+

classVEHMGR::~classVEHMGR()
{
	delete [] cpMODdev;
	delete cpMODhmi;
	//delete [] cpHMIsig;

}

// +------------------------------------+
//		classPushButton()
// +------------------------------------+

void classVEHMGR::PushButton()
{
	pioESTOP->readvalue();
	phAutoStart->checkstate();

	//cpHMIsig[ehAutoStart]->checkstate();
	//cpHMIsig[ehDestination]->checkstate();

}


// +------------------------------------+
//		classLigts()
// +------------------------------------+

void classVEHMGR::Lights()
{

}



