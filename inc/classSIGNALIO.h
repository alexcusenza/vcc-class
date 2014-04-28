/*
 * classSIGNALIO.h
 *
 *  Created on: Apr 26, 2014
 *      Author: acusenza
 */

#ifndef CLASSSIGNALIO_H_
#define CLASSSIGNALIO_H_

#include "classMODCONTROL.h"


// +------------------------------------+
// 		classSIGNALIO
// +------------------------------------+


class classSIGNALIO
{
public:
	classSIGNALIO(classMODCONTROL * , IONewType &);
	~classSIGNALIO();

	void checkstate();
	void rcviodata();
	void sendiodata();

private:
	const classMODCONTROL * mp_Port;
	const IONewType m_IO;
	//bool m_ACK;
	//bool m_REQ;

};


#endif /* CLASSSIGNALIO_H_ */
