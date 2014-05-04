/*
 * defsFUNC.h
 *
 *  Created on: May 3, 2014
 *      Author: acusenza
 */

#ifndef DEFSFUNC_H_
#define DEFSFUNC_H_

#include "defsGLOBAL.h"

FuncType fLoadLocation 	= { Function,	0,	0,	1 };
FuncType fImmHoldStop	= { Function,	0,	1,	1 };
FuncType fRouteSelect	= { Function,	0,	2, 	1 };
FuncType fStationCode	= { Function, 	0,	3, 	1 };
FuncType fSpeedSwitch	= { Function, 	0, 	4, 	1 };
FuncType fFrontBumper	= { Function, 	1,	0,	4 };
FuncType fRearBumper	= { Function,	1,	4, 	4 };

FuncType rSpeedSwitch	= { Route, 		0,	0,	1 };
FuncType rObjectOff		= { Route, 		0,	1,	1 };
FuncType rFrontBumper	= { Route,		1,	0,	4 };
FuncType rRearBumper	= { Route, 		1, 	4, 	4 };





#endif /* DEFSFUNC_H_ */
