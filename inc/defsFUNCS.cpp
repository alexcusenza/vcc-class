/*
 * defsFUNCS.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: acusenza
 */

//#include "classMODBASE.cpp"


void fIO_writeset(IONewType &tmpIONew, ModControlClass * tmpModPass[] )
{
	ModBaseClass * tmpModRegister;

	tmpModRegister = tmpModPass[tmpIONew.eDev];
	tmpModRegister->Write_Set(tmpIONew);

}

void fIO_writerst(IONewType &tmpIONew, ModControlClass * tmpModPass[] )
{
	ModBaseClass * tmpModRegister;

	tmpModRegister = tmpModPass[tmpIONew.eDev];
	tmpModRegister->Write_Rst(tmpIONew);
}

void fIO_read(IONewType &tmpIONew, ModControlClass * tmpModPass[] )
{
	ModBaseClass * tmpModRegister;

	tmpModRegister = tmpModPass[tmpIONew.eDev];
	tmpModRegister->ReadValue(tmpIONew);
}


void fIO_writefield(IONewType &tmpIONew, int tmpval, ModControlClass * tmpModPass[])
{
	ModBaseClass * tmpModRegister;

	tmpModRegister = tmpModPass[tmpIONew.eDev];
	tmpModRegister->Write_Field(tmpIONew, tmpval);

}


