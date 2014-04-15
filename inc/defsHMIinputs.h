/*
 * defsHMITYPE.h
 *
 *  Created on: Apr 11, 2014
 *      Author: acusenza
 */

#ifndef DEFSHMITYPE_H_
#define DEFSHMITYPE_H_

#include "defsGLOBAL.h"

HMIType hmiInputs[]= {
		/* Name						Type		Data	Word	Size */
		{ "SendMagData", 			tBool, 		false, 	0, 		1 },
		{ "MagCalibration",			tBool, 		false,	1,		1 },
		{ "AutoStart",				tBool,		false,	2,		1 },
		{ "AutoStop", 				tBool,		false,	3,		1 },
		{ "Destination",			tBool,		true,	4,		1 },
		{ "Destination_data", 		tWord,		false,	5,		1 },
		{ "Operation",				tBool,		true,	6,		1 },
		{ "Operation_data",			tWord,		false,	7,		1 },
		{ "IPaddress",				tBool,		true,	8,		1 },
		{ "IPaddress_data",			tWord,		false,	9,		2 },
		{ "IPmask",					tBool,		true,	11,		1 },
		{ "IPmask_data",			tWord,		false,	12, 	2 },
		{ "GyroCorrection",			tBool,		true,	14,		1 },
		{ "GyroCorrection_data",	tWord,		false,	15,		2 }
};


#endif /* DEFSHMITYPE_H_ */
