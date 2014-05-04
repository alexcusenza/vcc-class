/*
 * defsFUNCS.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: acusenza
 */

//#include "classMODBASE.cpp"














/*
 * OLD IO Write/Read Routines
 */
void fIO_writeset(IODefType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Set(tIONew);

}

void fIO_writerst(IODefType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Rst(tIONew);
}

void fIO_read(IODefType &tIONew, classMODCONTROL * tModPass[] )
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->ReadValue(tIONew);
}


void fIO_writefield(IODefType &tIONew, int tval, classMODCONTROL * tModPass[])
{
	classMODBASE * tModRegister;

	tModRegister = tModPass[tIONew.eDev];
	tModRegister->Write_Field(tIONew, tval);

}


