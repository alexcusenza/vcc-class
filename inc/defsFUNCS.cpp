/*
 * defsFUNCS.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: acusenza
 */

//#include "classMODBASE.cpp"


void fIO_writeset(IONewType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Set(tIONew);
}

void fIO_writerst(IONewType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Rst(tIONew);
}

void fIO_read(IONewType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->ReadValue(tIONew);
}


void fIO_writefield(IONewType &tIONew, int tval, classMODCONTROL * tModPass[])
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Field(tIONew, tval);

}


