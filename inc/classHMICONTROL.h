/*
 * classHMICONTROL.H
 *
 *  Created on: Apr 10, 2014
 *      Author: acusenza
 */

#ifndef CLASSHMICONTROL_H_
#define CLASSHMICONTROL_H_
#include "classMODCONTROL.h"


#include "classMODREGISTER.h"


// +------------------------------------+
// 		classHMICONTROL
// +------------------------------------+


class classHMICONTROL
{

public:

	classHMICONTROL(classMODREGISTER & tmpPort);
	~classHMICONTROL();

	void checkstate();
	void rcvhmidata();
	void sendhmidata();

protected:
	classMODREGISTER & m_Port;

private:



};

#endif /* CLASSHMICONTROL_H_ */
