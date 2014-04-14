/*
 * classIOPOLY.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: acusenza
 */

#include <iostream>
#include "defsIOTYPE.h"
#include "defsGLOBAL.h"

// +--------------------------+
// 		IOAccessClass
// +--------------------------+

class IOAccessClass
{
public:
	IOAccessClass( eIODevType eIOdev);

	virtual int WriteSet(IONewType &) = 0;
	virtual int WriteRst(IONewType &) = 0;

protected:
	int a, b;
	eIODevType eIOdev;

};



// +--------------------------+
// 		IOPlcClass
// +--------------------------+

class IOPlcClass : public IOAccessClass
{
public:
	IOPlcClass(eIODevType eIOdev);
	virtual int WriteSet(IONewType &);
	virtual int WriteRst(IONewType &);
};


IOPlcClass::IOPlcClass (eIODevType eIOdev) : IOAccessClass(eIOdev) { }

int IOPlcClass::WriteSet(IONewType &tempIONew)
{
	if(tempIONew.eIO == PLC)
	{
		if (tempIONew.eDir == OUT)
		{

		}
		else
			printf("wrong direction\n");

	}
	else
		printf("wrong device\n");

	return 0;
}

int IOPlcClass::WriteRst(IONewType &tempIONew)
{
	if(tempIONew.eIO == PLC)
	{
		if (tempIONew.eDir == OUT)
		{

		}
		else
			printf("wrong direction\n");

	}
	else
		printf("wrong device\n");

	return 0;
}



// +--------------------------+
// 		IOSickClass
// +--------------------------+

class IOSickClass : public IOAccessClass
{
public:
	IOSickClass(eIODevType eIOdev);
	int WriteSet(IONewType &);

};

IOSickClass::IOSickClass (eIODevType eIOdev) : IOAccessClass(eIOdev) { }

int IOSickClass::WriteSet(IONewType &tempIONew)
{
	if(tempIONew.eIO == SICK0)
	{


	}
	else
		printf("wrong device\n");
	return 0;
}


