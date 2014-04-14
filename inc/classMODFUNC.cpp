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

ModFuncRead02hClass::ModFuncRead02hClass (char a, int b)
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

int ModFuncRead02hClass::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncRead02hType ModFuncRead02hClass::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void ModFuncRead02hClass::set_Address(int address) {
	sModbusFunc.Address = htons(address);
}

void ModFuncRead02hClass::set_SizeBytes(int size) {
	sModbusFunc.SizeBytes = htons(size);
}

//void set_Length() {
//	sModbusFunc.Length = TransCnt;
//}

void ModFuncRead02hClass::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);
	//set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



// +------------------------------------+
// 		ModFuncRead03h: CLASS
// +------------------------------------+

ModFuncRead03hClass::ModFuncRead03hClass (char a, int b)
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


int ModFuncRead03hClass::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncRead03hType ModFuncRead03hClass::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void ModFuncRead03hClass::set_Address(int address) {
	sModbusFunc.Address = htons(address);
}

void ModFuncRead03hClass::set_SizeWords(int size) {
	sModbusFunc.SizeWords = htons(size);
}

//void set_Length() {
//	sModbusFunc.Length = TransCnt;
//}

void ModFuncRead03hClass::set_MsgByteCnt(int x)
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

ModFuncWrite0FhClass::ModFuncWrite0FhClass (char a, int b)
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

int ModFuncWrite0FhClass::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncWrite0FhType ModFuncWrite0FhClass::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}


void ModFuncWrite0FhClass::set_Address(int address) {
	sModbusFunc.Address = address;
}

void ModFuncWrite0FhClass::set_SizeBits(int sizew) {
	sModbusFunc.SizeBits = sizew;
}

void ModFuncWrite0FhClass::set_SizeBytes(int sizeb) {
	sModbusFunc.SizeBytes = sizeb;
}

void ModFuncWrite0FhClass::set_Length () {
	sModbusFunc.Length = TransCnt + sModbusFunc.SizeBytes;
}

void ModFuncWrite0FhClass::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);
	set_SizeBits(x*8);
	set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



// +------------------------------------+
// 		ModFuncWrite10h: CLASS
// +------------------------------------+

ModFuncWrite10hClass::ModFuncWrite10hClass (char a, int b)
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


int ModFuncWrite10hClass::get_MsgByteCnt()
{
	return (MsgByteCnt);
}

ModFuncWrite10hType ModFuncWrite10hClass::get_ModStruct(int x) {
	set_MsgByteCnt(x);
	return this->sModbusFunc;
}

void ModFuncWrite10hClass::set_Address(int address) {
	sModbusFunc.Address = address;
}

void ModFuncWrite10hClass::set_SizeWords(int sizew) {
	sModbusFunc.SizeWords = sizew;
}

void ModFuncWrite10hClass::set_SizeBytes(int sizeb) {
	sModbusFunc.SizeBytes = sizeb;
}

void ModFuncWrite10hClass::set_Length () {
	sModbusFunc.Length = TransCnt + sModbusFunc.SizeBytes;
}

void ModFuncWrite10hClass::set_MsgByteCnt(int x)
{
	set_SizeBytes(x);

	if (x%2 == 0)
		set_SizeWords(x/2);		// even
		else
			set_SizeWords(x/2 + 1);	// odd

	set_Length();
	MsgByteCnt = ProtoHdrCnt + TransCnt;
}



