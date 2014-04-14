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
// 		ModRegisterClass: CLASS
// +------------------------------------+

class ModRegisterClass: public ModBaseClass
{

public:

	ModRegisterClass(int);
	~ModRegisterClass();

	void ConfigRegister(IONewType &);
	void Write_Set(IONewType &);
	void Write_Rst(IONewType &);
	int ReadValue(IONewType &);

	void Write_Field(IONewType &, int);
	void Read_Field(IONewType &, int);

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
