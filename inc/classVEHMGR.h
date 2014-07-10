/*
 * classVEHMGR.h
 *
 *  Created on: May 3, 2014
 *      Author: acusenza
 */

#ifndef CLASSVEHMGR_H_
#define CLASSVEHMGR_H_


// ******* CLASSES ************
//#include "../inc/classMODFUNC.h"
#include "../inc/classMODCONTROL.h"
//#include "../inc/classMODREGISTER.h"
#include "../inc/classSIGNALHMI.h"
#include "../inc/classSIGNALIO.h"


// ******* DEFINITIONS *********
//#include "../inc/defsIOTYPE.h"
//#include "../inc/defsGLOBAL.h"
//#include "../inc/defsFUNCS.cpp"
//#include "../inc/defsHMIinputs.h"


class classVEHMGR
{
public:

	classVEHMGR();
	~classVEHMGR();
	void PushButton();
	void Lights();
	void Horn();
	void HoldStop();
	void Battery();

private:

	classMODCONTROL * cpMODdev[MaxDev];
	classMODCONTROL * cpMODhmi;
	//classSIGNALHMI * cpHMIsig[5];

	classSIGNALIO * pioESTOP;
	classSIGNALIO * pioSTART;
	classSIGNALIO * pioSICKBUMPER;

	classSIGNALHMI * phAutoStart;
	classSIGNALHMI * phDestination;


	int vmDestination;
	int vmLocation;
	int vmOperation;
	int vmFloorCode;
	int vmCVS;
	int vmDirection;
	bool vmReleased;
	bool vmAutoOn;
	bool vmCharging;
};



#endif /* CLASSVEHMGR_H_ */
