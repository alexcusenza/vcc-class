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
	MaxDev,
	HMI
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

enum eNOCType
{
	no,		// normal open		: 0 for open, 1 for closed
	nc		// normal closed 	: 0 for closed, 1 for open
};

enum eDataType
{
	tBool,
	tChar,
	tByte,
	tWord,
	tDouble,
	tNone
};

enum eFuncType
{
	Function,
	Route
};


struct IODefType
{
	eDevType eDev;
	eDirType eDir;
	eDataType eData;
	int Word;
	int Bit;
	int Width;
};

struct HMIType
{
	//const char * name;
	eDataType eData;
	int Word;
	int Bit;
	int Width;
};

struct FuncType
{
	eFuncType eFunc;
	int Word;
	int Bit;
	int Width;
};




#endif /* DEFSGLOBAL_H_ */
