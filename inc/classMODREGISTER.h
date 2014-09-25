/*
 * classMODREGISTER.h
 *
 *  Created on: Mar 23, 2014
 *      Author: acusenza
 */

#ifndef CLASSMODREGISTER_H_
#define CLASSMODREGISTER_H_

//#include "defsIOTYPE.h"
#include "defsGLOBAL.h"
#include "classMODBASE.h"

struct MODdataType
{
	short inword[4];
	short outword[4];
};


// +------------------------------------+
// 		classMODREGISTER: CLASS
// +------------------------------------+

class classMODREGISTER: public classMODBASE
{

public:

	classMODREGISTER(int);
	~classMODREGISTER();

	void ConfigRegister(IODefType &);
	//void Write_Set(IODefType &);
	//void Write_Rst(IODefType &);
	void WriteValue(IODefType &, eSetRstType);
	int ReadValue(IODefType &);

	void Write_Field(IODefType &, int);
	void Read_Field(IODefType &, int);

	int get_datain(void);
	MODdataType get_iomap();

protected:
	MODdataType sMODdata;
	int m_datain;

private:
	int m_Device;
	char m_DevName[32];
};

#endif /* CLASSMODREGISTER_H_ */
