/*
 * classMODFUNC.h
 *
 *  Created on: Mar 24, 2014
 *      Author: acusenza
 */

#ifndef CLASSMODFUNC_H_
#define CLASSMODFUNC_H_


// +------------------------------------+
// 		ModFuncRead02h: STRUCTURE
// +------------------------------------+

struct ModFuncRead02hType
{
	short TransID;
	short ProtoID;
	short Length;
	char UnitID;
	char Function;
	short Address;
	short SizeBytes;
};

// +------------------------------------+
// 		ModFuncRead02h: CLASS
// +------------------------------------+

class ModFuncRead02hClass
{
public:

	ModFuncRead02hClass (char a, int b);

	int get_MsgByteCnt();

	ModFuncRead02hType get_ModStruct(int x) ;

private:

	void set_Address(int address) ;

	void set_SizeBytes(int size) ;

	void set_MsgByteCnt(int x);

	struct ModFuncRead02hType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;
};


// +------------------------------------+
// 		ModFuncRead03h: STRUCTURE
// +------------------------------------+

struct ModFuncRead03hType
{
	short TransID;
	short ProtoID;
	short Length;
	char UnitID;
	char Function;
	short Address;
	short SizeWords;
};

// +------------------------------------+
// 		ModFuncRead03h: CLASS
// +------------------------------------+

class ModFuncRead03hClass
{
public:

	ModFuncRead03hClass (char a, int b);

	int get_MsgByteCnt();

	ModFuncRead03hType get_ModStruct(int x) ;

private:

	void set_Address(int address) ;

	void set_SizeWords(int size) ;

	void set_MsgByteCnt(int x);

	struct ModFuncRead03hType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;
};

// +------------------------------------+
// 		ModFuncWrite0Fh: STRUCTURE
// +------------------------------------+

struct ModFuncWrite0FhType
{
	short TransID;
	short ProtoID;
	short Length;
	char UnitID;
	char Function;
	short Address;
	short SizeBits;
	char SizeBytes;
};


// +------------------------------------+
//		ModFuncWrite0Fh: CLASS
// +------------------------------------+

class ModFuncWrite0FhClass
{
public:

	ModFuncWrite0FhClass (char a, int b);

	int get_MsgByteCnt();

	ModFuncWrite0FhType get_ModStruct(int x) ;

private:

	void set_Address(int address) ;

	void set_SizeBits(int sizew);

	void set_SizeBytes(int sizeb) ;

	void set_Length () ;

	void set_MsgByteCnt(int x);

	struct ModFuncWrite0FhType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;
};

// +------------------------------------+
// 		ModFuncWrite10h: STRUCTURE
// +------------------------------------+

struct ModFuncWrite10hType
{
	short TransID;
	short ProtoID;
	short Length;
	char UnitID;
	char Function;
	short Address;
	short SizeWords;
	char SizeBytes;
};


// +------------------------------------+
// 		ModFuncWrite10h: CLASS
// +------------------------------------+

class ModFuncWrite10hClass
{
public:

	ModFuncWrite10hClass (char a, int b);

	int get_MsgByteCnt();

	ModFuncWrite10hType get_ModStruct(int x);

private:

	void set_Address(int address) ;

	void set_SizeWords(int sizew) ;

	void set_SizeBytes(int sizeb) ;

	void set_Length () ;

	void set_MsgByteCnt(int x);

	struct ModFuncWrite10hType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;
};


#endif /* CLASSMODFUNC_H_ */
