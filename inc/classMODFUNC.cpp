/*
 * modfunc.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: acusenza
 */

#include "classMODFUNC.h"
#include "defsGLOBAL.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>



// +------------------------------------+
//		ModFuncWrite02h: CLASS
// +------------------------------------+

classModFuncRead02h::classModFuncRead02h (char a, int b)
{
	sModbusFunc.TransID = 0;
	sModbusFunc.ProtoID = 0;
	sModbusFunc.Length = htons(6);		// 6 bytes: uid-1 + func-1 + addr-2 + bytes-2
	sModbusFunc.UnitID = a;
	sModbusFunc.Function = 2;
	sModbusFunc.Address = htons(b);
	sModbusFunc.SizeBytes = 0;
	ProtoHdrCnt = 6;
	TransCnt = 6;
	MsgByteCnt = 0;

	printf("ModFuncRead 02h created, Unit ID: %d\n", sModbusFunc.UnitID );
}

int classModFuncRead02h::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncRead02hType classModFuncRead02h::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void classModFuncRead02h::set_Address(int address) {
	sModbusFunc.Address = htons(address);
}

void classModFuncRead02h::set_SizeBytes(int size) {
	sModbusFunc.SizeBytes = htons(size);
}

//void set_Length() {
//	sModbusFunc.Length = TransCnt;
//}

void classModFuncRead02h::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);
	//set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



// +------------------------------------+
// 		ModFuncRead03h: CLASS
// +------------------------------------+

classModFuncRead03h::classModFuncRead03h (char a, int b)
{
	sModbusFunc.TransID = 0;
	sModbusFunc.ProtoID = 0;
	sModbusFunc.Length = htons(6);		// 6 bytes: uid-1 + func-1 + addr-2 + bytes-2
	sModbusFunc.UnitID = a;
	sModbusFunc.Function = 3;
	sModbusFunc.Address = b;
	sModbusFunc.SizeWords = 0;
	ProtoHdrCnt = 6;
	TransCnt = 6;
	MsgByteCnt = 0;

	printf("ModFuncRead 03h created, Unit ID: %d\n", sModbusFunc.UnitID );
}


int classModFuncRead03h::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncRead03hType classModFuncRead03h::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void classModFuncRead03h::set_Address(int address) {
	sModbusFunc.Address = htons(address);
}

void classModFuncRead03h::set_SizeWords(int size) {
	sModbusFunc.SizeWords = htons(size);
}

//void set_Length() {
//	sModbusFunc.Length = TransCnt;
//}

void classModFuncRead03h::set_MsgByteCnt(int x)
{
	if (x%2 == 0)
		set_SizeWords(x/2);		// even
	else
		set_SizeWords(x/2 + 1);	// odd

	//set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



// +------------------------------------+
//		ModFuncWrite0Fh: CLASS
// +------------------------------------+

classModFuncWrite0Fh::classModFuncWrite0Fh (char a, int b)
{
	sModbusFunc.TransID = 0;
	sModbusFunc.ProtoID = 0;
	sModbusFunc.Length = 7;		// 7 bytes: uid(1) + func(1) + addr(2) + bits(2) + bytes(1)
	sModbusFunc.UnitID = a;
	sModbusFunc.Function = 0x0f;
	sModbusFunc.Address = htons(b);
	sModbusFunc.SizeBits = 0;
	sModbusFunc.SizeBytes = 0;

	ProtoHdrCnt = 6;	// 6 bytes: TransID(2) + ProtoID(2) + Length(2)
	TransCnt = 7;
	MsgByteCnt = 0;
	printf("ModFuncRead 0fh created, Unit ID: %d\n", sModbusFunc.UnitID );
}

int classModFuncWrite0Fh::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncWrite0FhType classModFuncWrite0Fh::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void classModFuncWrite0Fh::set_Address(int address) {
	sModbusFunc.Address = address;
}

void classModFuncWrite0Fh::set_SizeBits(int sizew) {
	sModbusFunc.SizeBits = sizew;
}

void classModFuncWrite0Fh::set_SizeBytes(int sizeb) {
	sModbusFunc.SizeBytes = sizeb;
}

void classModFuncWrite0Fh::set_Length () {
	sModbusFunc.Length = TransCnt + sModbusFunc.SizeBytes;
}

void classModFuncWrite0Fh::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);
	set_SizeBits(x*8);
	set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



// +------------------------------------+
// 		ModFuncWrite10h: CLASS
// +------------------------------------+

classModFuncWrite10h::classModFuncWrite10h (char a, int b)
{
	sModbusFunc.TransID = 0;
	sModbusFunc.ProtoID = 0;
	sModbusFunc.Length = htons(7);		// 7 bytes: uid-1 + func-1 + addr-2 + byte-1 + word-2
	sModbusFunc.UnitID = a;
	sModbusFunc.Function = 0x10;
	sModbusFunc.Address = htons(b);
	sModbusFunc.SizeWords = 0;
	sModbusFunc.SizeBytes = 0;
	MsgByteCnt = 0;
	ProtoHdrCnt = 6;	// 6 bytes: TransID(2) + ProtoID(2) + Length(2)
	TransCnt = 7;
	MsgByteCnt = 0;

	printf("ModFuncRead 10h created, Unit ID: %d\n", sModbusFunc.UnitID );
};


int classModFuncWrite10h::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncWrite10hType classModFuncWrite10h::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}

void classModFuncWrite10h::set_Address(int address) {
	sModbusFunc.Address = address;
}

void classModFuncWrite10h::set_SizeWords(int sizew) {
	sModbusFunc.SizeWords = sizew;
}

void classModFuncWrite10h::set_SizeBytes(int sizeb) {
	sModbusFunc.SizeBytes = sizeb;
}

void classModFuncWrite10h::set_Length () {
	sModbusFunc.Length = TransCnt + sModbusFunc.SizeBytes;
}

void classModFuncWrite10h::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);

	if (x%2 == 0)
		set_SizeWords(x/2);		// even
		else
			set_SizeWords(x/2 + 1);	// odd

	set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



