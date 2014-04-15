/*
 * globaldefs.h
 *
 *  Created on: Mar 7, 2014
 *      Author: acusenza
 */

#ifndef DEFSGLOBAL_H_
#define DEFSGLOBAL_H_

enum eDevType
{
	PLC,
	SICK0,
	SICK1,
	MaxDev
};

enum eCmdType
{
	readcmd,
	readresp,
	writecmd,
	writeresp
};


enum eDirType
{
	IN,
	OUT
};

enum eDataType
{
	tBool,
	tChar,
	tByte,
	tWord,
	tDouble
};


struct IONewType
{
	eDevType eDev;
	eDirType eDir;
	int Word;
	int Bit;
	int Width;
};

struct HMIType
{
	const char * name;
	eDataType eHMI;
	bool Data;
	int Word;
	int Width;
};





#endif /* DEFSGLOBAL_H_ */
