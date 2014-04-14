/*
 * defsHMITYPE.h
 *
 *  Created on: Apr 11, 2014
 *      Author: acusenza
 */

#ifndef DEFSHMITYPE_H_
#define DEFSHMITYPE_H_

#include "defsGLOBAL.h"
									/* 	Type	Word	Size */
HMIType hmiSendMagData 				= {	tBool, 	0, 		1 };
HMIType hmiMagCalibration			= {	tBool, 	1, 		1 };
HMIType hmiAutoStart				= {	tBool, 	2,		1 };
HMIType	hmiAutoStop					= {	tBool, 	3,		1 };

HMIType hmiDestination[]			= {	tBool, 	4, 		1,
										tWord, 	5, 		1 };

HMIType hmiOperation[]				= {	tBool, 	6,		1,
										tWord, 	7,		1 };

HMIType	hmiIPaddress[]				= {	tBool, 	8,		1,
										tWord,	9,		2 };

HMIType hmiIPmask[]					= {	tBool,	11,		1,
										tWord, 	12,		2 };

HMIType hmiGyroCorrection[]			= {	tBool,	14,		1,
										tWord,	15,		2 };




#endif /* DEFSHMITYPE_H_ */
