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

HMIType hSendMagData 		= { tBool, 0,	0,	1 };
HMIType hMagCalibration		= { tBool, 0, 	1,	1 };
HMIType	hAutoStart			= { tBool, 0,	2,	1 };
HMIType hAutoStop			= { tBool, 0,	3,	1 };
HMIType hDestination		= { tBool, 0, 	4,	1 };
HMIType hOperation			= { tBool, 0,	5,	1 };
HMIType hRoute				= { tBool, 0,	6,	1 };
HMIType hIPaddress			= { tBool, 0,	7,	1 };



#endif /* DEFSHMITYPE_H_ */
