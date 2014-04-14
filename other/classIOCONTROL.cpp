/*
 * c_modstruct.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: acusenza
 */

#include <iostream>
#include "defsIOTYPE.h"
#include "defsGLOBAL.h"


class IOControlClass
{
public:

	IOControlClass(){
		memset(&sIOmap, 0, sizeof(sIOmap));
	};

	int Write_Set( IOType & );
	int Write_Rst( IOType & );
	int Read_Input( IOType & );
	int Read_Output( IOType & );

	int NewWrite_Set( IONewType &);

	IOMapType get_iomap();

private:
	struct IOMapType sIOmap;
	int datain;
};


int IOControlClass::NewWrite_Set(IONewType &newiotemp)
{
	if(newiotemp.eDev == PLC)
	{


	}
	return 0;
}


int IOControlClass::Write_Set( IOType &ioctmp)
{
	if (ioctmp.eDir == OUT)
	{
		sIOmap.outputword[ioctmp.Word] |= (1 << ioctmp.Bit);
	}
	else
	{
		printf("ERROR: not an output\n");
		return -1;
	}
	return 0;
}

int IOControlClass::Write_Rst(IOType &ioctmp)
{
	if (ioctmp.eDir == OUT)
	{
		sIOmap.outputword[ioctmp.Word] &= ~(1 << ioctmp.Bit);
	}
	else
	{
		printf("ERROR: not an output\n");
		return -1;
	}
	return 0;
}

int IOControlClass::Read_Input( IOType &ioctmp)
{
	if (ioctmp.eDir == IN)
	{
		datain = sIOmap.inputword[ioctmp.Word];
		return (datain);
	}
	else
	{
		printf("ERROR: not an input\n");
		return -1;
	}
	return 0;
}

int IOControlClass::Read_Output(IOType &ioctmp)
{
	if (ioctmp.eDir == OUT)
	{
		datain = sIOmap.outputword[ioctmp.Word];
		return (datain);
	}
	else
	{
		printf("ERROR: not an output\n");
		return 0;
	}
}

IOMapType IOControlClass::get_iomap()
{
	return this->sIOmap;
}


