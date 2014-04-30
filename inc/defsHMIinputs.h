/*
 * defsHMITYPE.h
 *
 *  Created on: Apr 11, 2014
 *      Author: acusenza
 */

#ifndef DEFSHMITYPE_H_
#define DEFSHMITYPE_H_

#include "defsGLOBAL.h"


/*HMIType hmiInputs[]= {
		 Name						Type		Word	Size
		{ "SendMagData", 			tBool, 		0, 		1 },
		{ "MagCalibration",			tBool, 		1,		1 },
		{ "AutoStart",				tBool,		2,		1 },
		{ "AutoStop", 				tBool,		3,		1 },
		{ "Destination",			tBool,		4,		1 },
		{ "Operation",				tBool,		5,		1 },
		{ "Route",					tBool,		6,		1 },
		{ "IPaddress",				tBool,		7,		1 },
		{ "IPmask",					tBool,		8,		1 },
		{ "GyroCorrection",			tBool,		9,		1 }
};*/

IODefType hSendMagData 			= { HMI,	IN,	tBool, 0,	0,	1 };
IODefType hMagCalibration		= { HMI,	IN,	tBool, 0, 	1,	1 };
IODefType hAutoStart			= { HMI,	IN,	tBool, 0,	2,	1 };
IODefType hAutoStop				= { HMI,	IN,	tBool, 0,	3,	1 };
IODefType hDestination			= { HMI,	IN,	tBool, 0, 	4,	1 };
IODefType hOperation			= { HMI,	IN,	tBool, 0,	5,	1 };
IODefType hRoute				= { HMI,	IN,	tBool, 0,	6,	1 };
IODefType hIPaddress			= { HMI,	IN,	tBool, 0,	7,	1 };



#endif /* DEFSHMITYPE_H_ */
