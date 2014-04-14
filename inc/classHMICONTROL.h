/*
 * classHMICONTROL.H
 *
 *  Created on: Apr 10, 2014
 *      Author: acusenza
 */

#ifndef CLASSHMICONTROL_H_
#define CLASSHMICONTROL_H_

#include "classMODCONTROL.h"


// +------------------------------------+
// 		classHMICONTROL
// +------------------------------------+


class classHMICONTROL: public ModControlClass
{

public:

	classHMICONTROL(int);
	~classHMICONTROL();

	void checkstate();
	void rcvhmidata();
	void sendhmidata();


private:


};

#endif /* CLASSHMICONTROL_H_ */
