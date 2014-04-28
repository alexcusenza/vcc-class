/*
 * classSIGNALHMI.H
 *
 *  Created on: Apr 10, 2014
 *      Author: acusenza
 */

#ifndef CLASSHMICONTROL_H_
#define CLASSHMICONTROL_H_

#include "classMODCONTROL.h"


// +------------------------------------+
// 		classSIGNALHMI
// +------------------------------------+


class classSIGNALHMI
{
public:
	classSIGNALHMI(classMODCONTROL * , HMIType &);
	~classSIGNALHMI();

	void checkstate();
	void rcvhmidata();
	void sendhmidata();

private:
	classMODCONTROL * mp_Port;
	HMIType m_HMI;
	bool m_oneshot;

};

#endif /* CLASSHMICONTROL_H_ */
