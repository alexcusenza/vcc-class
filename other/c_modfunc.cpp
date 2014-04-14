/*
 * modfunc.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: acusenza
 */

#include <iostream>
#include "globaldefs.h"

// STRUCTURE: ModFuncRead02h
// --------------------------

struct ModFuncRead02hType
{
	short TransID;
	short ProtoID;
	short Length;
	char UnitID;
	char Function;
	short Address;
	short SizeWords;
};


// CLASS: ModFuncRead02h
// ---------------------
/*
 *  implementation of MODBUS ReadMessage
 */

class ModFuncRead02hClass
{
public:
	ModFuncRead02hClass (char a, int b)
{
		sModbusFunc.TransID = htons(0);
		sModbusFunc.ProtoID = htons(0);
		sModbusFunc.Length = htons(6);		// 6 bytes: uid-1 + func-1 + addr-2 + bytes-2
		sModbusFunc.UnitID = a;
		sModbusFunc.Function = 2;
		sModbusFunc.Address = htons(b);
		sModbusFunc.SizeWords = 0;
		MsgByteCnt = 0;
		ProtoHdrCnt = 6;
		TransCnt = 6;
		cout << "ModFuncRead02h created, Unit ID: " << sModbusFunc.UnitID << endl;
};

	int get_AllBytes()
	{
		return (MsgByteCnt);
	}

	ModFuncRead02hType get_ModStruct(int x) {
		set_AllBytes(x);
		return this->sModbusFunc;
	}

private:

	void set_Address(int address) {
		sModbusFunc.Address = address;
	}

	void set_SizeWords(int size) {
		sModbusFunc.SizeWords = size;
	}

	void set_Length() {
		sModbusFunc.Length = TransCnt;
	}

	void set_AllBytes(int x)
	{
		set_SizeWords(x);
		set_Length();
		MsgByteCnt = ProtoHdrCnt + TransCnt;
	}

	struct ModFuncRead02hType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;

};



// STRUCTURE: ModFuncRead03h
// --------------------------

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

// CLASS: ModFuncRead03h
// -----------------
/*
 *  implementation of MODBUS ReadMessage
 */

class ModFuncRead03hClass
{
public:
	ModFuncRead03hClass (char a, int b, int c)
{
		sModbusFunc.TransID = htons(0);
		sModbusFunc.ProtoID = htons(0);
		sModbusFunc.Length = htons(6);		// 6 bytes: uid-1 + func-1 + addr-2 + bytes-2
		sModbusFunc.UnitID = a;
		sModbusFunc.Function = 3;
		sModbusFunc.Address = htons(b);
		sModbusFunc.SizeWords = htons(c);

		cout << "ModFuncRead03h created, Unit ID: " << sModbusFunc.UnitID << endl;
};

	void set_Address(int address) {
		sModbusFunc.Address = address;
	}

	void set_SizeWords(int size) {
		sModbusFunc.SizeWords = size;
	}

	ModFuncRead03hType get_ModStruct() {
		return this->sModbusFunc;
	}

private:
	struct ModFuncRead03hType sModbusFunc;

};


//   STRUCTURE: ModFuncWrite10h
//  ----------------------------

struct ModFuncWrite10hType
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

//  CLASS: ModFuncWrite10h
//  -----------------------

/*
 *  implementation of MODBUS Write 10h
 */

class ModFuncWrite10Class
{
public:
	ModFuncWrite10Class (char a, int b, int c, int d)
{
		sModbusFunc.TransID = 0;
		sModbusFunc.ProtoID = 0;
		sModbusFunc.Length = htons(7);		// 7 bytes: uid-1 + func-1 + addr-2 + byte-1 + word-2
		sModbusFunc.UnitID = a;
		sModbusFunc.Function = 0x10;
		sModbusFunc.Address = htons(b);
		sModbusFunc.SizeBits = htons(c);
		sModbusFunc.SizeBytes = d;
		MsgByteCnt = 0;

		cout << "ModFuncWrite10h created, Unit ID: " << sModbusFunc.UnitID << endl;
};

	void set_Address(int address) {
		sModbusFunc.Address = address;
	}

	void set_SizeWords(int sizew) {
		sModbusFunc.SizeBits = sizew;
	}

	void set_SizeBytes(int sizeb) {
		sModbusFunc.SizeBytes = sizeb;
	}

	void set_Length () {
		int tmp = sModbusFunc.Length + sModbusFunc.SizeBytes;
		sModbusFunc.Length = htons(tmp);
	}

	ModFuncWrite10hType get_ModStruct() {
		return this->sModbusFunc;
	}

private:
	struct ModFuncWrite10hType sModbusFunc;
	int MsgByteCnt;
};




//  STRUCTURE: ModFuncWrite0Fh
//  ---------------------------

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


//  CLASS: ModFuncWrite0Fh
//  -----------------

/*
 *  Class Definition
 *  implementation of MODBUS Write 10h
 */

class ModFuncWrite0FhClass
{
public:
	ModFuncWrite0FhClass (char a, int b)
{
		sModbusFunc.TransID = 0;
		sModbusFunc.ProtoID = 0;
		sModbusFunc.Length = 7;		// 7 bytes: uid(1) + func(1) + addr(2) + bits(2) + bytes(1)
		sModbusFunc.UnitID = a;
		sModbusFunc.Function = 0x0f;
		sModbusFunc.Address = htons(b);
		sModbusFunc.SizeBits = 0;
		sModbusFunc.SizeBytes = 0;
		MsgByteCnt = 0;					// 6 bytes: TransID(2) + ProtoID(2) + Length(2)
		ProtoHdrCnt = 6;
		TransCnt = 7;
		cout << "ModFuncWrite0Fh created, Unit ID: " << sModbusFunc.UnitID << endl;
};

	int get_AllBytes()
	{
		return (MsgByteCnt);
	}

	ModFuncWrite0FhType get_ModStruct(int x) {
		set_AllBytes(x);
		return this->sModbusFunc;
	}

private:
	void set_Address(int address) {
		sModbusFunc.Address = address;
	}

	void set_SizeBits(int sizew) {
		sModbusFunc.SizeBits = sizew;
	}

	void set_SizeBytes(int sizeb) {
		sModbusFunc.SizeBytes = sizeb;
	}

	void set_Length () {
		sModbusFunc.Length = TransCnt + sModbusFunc.SizeBytes;
	}

	void set_AllBytes(int x)
	{
		set_SizeBytes(x);
		set_SizeBits(x*8);
		set_Length();
		MsgByteCnt = ProtoHdrCnt + TransCnt;
	}

	struct ModFuncWrite0FhType sModbusFunc;
	int ProtoHdrCnt;
	int TransCnt;
	int MsgByteCnt;
};

