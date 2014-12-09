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
	classSIGNALIO(classMODCONTROL * , IODefType &);
	~classSIGNALIO();

	void write_set();
	void write_rst();
	void readvalue();
	void writevalue(eSetRstType);
	void write_field(int);

private:
	classMODCONTROL * mp_Port;
	IODefType m_IO;

};


#endif /* CLASSSIGNALIO_H_ */
