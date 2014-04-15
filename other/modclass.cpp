/*
 * modclass02.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: acusenza
 */


/*
 * attempt to implement a structure and a class
 */
using namespace std;

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "c_modfunc.cpp"
#include "c_modcontrol.cpp"
#include "c_iocontrol.cpp"
#include "iodefs.h"
#include "globaldefs.h"



//struct IOType sPLCMAP;
#define dPlcUID 0
#define dSickUID 1

//char ips = "172.16.17.100";


/*
 * MAIN PROGRAM
 * ------------
 */

int main(void)
{
	int result, sizemsg, sizedata;
	// TEST c_modfunc class
	// ---------------------
	printf("******************************* \n");
	printf("***** STARTING CLASS TEST ***** \n");
	printf("******************************* \n");
	/*
	 * This class sets up the parameters and structures for the modbus function reads and writes
	 * It is intended to pass this to a structure using get_ModReadStruct() and pass to the next
	 * class c_classMODCONTROL
	 */

	// --- PLC READ / WRITE ---
	/*
	 *  Instantiate the first class for modplcread, which is the modbus function 02h protocol
	 *  modbus function 0fh write protocol
	 */
	classModFuncRead02h cPLCfuncread02h(dPlcUID, 0x1234);
	struct ModFuncRead02hType sPLCfuncread02h;


	classModFuncWrite0Fh cPLCfuncwrite0fh(dPlcUID, 0x1);
	struct ModFuncWrite0FhType sPLCfuncwrite0fh;

	// Instantiate Modbus control class
	classMODCONTROL cPLCmodcontrol;

	// Instantiate IO control class
	c_IOControl cPLCio;
	struct IOMapType sPLCiomap;


	// --- SICK READ / WRITE ---
	//classModFuncWrite10h c_modsick(dSickUID, 1234, 5, 5);
	//struct s_ModFuncWrite10hType s_modsickwritefunc;


	// --- PLC READ/WRITE calling getting structure ---
	/*
	 *  Read and Write Modbus function structure and class setup
	 *  Only requires to call .get_ModStruct(x) function.  Enter
	 *  the appropriate size of bytes or words, whatever the modbus
	 *  function calls for.
	 *
	 *  These structures: sPLCfuncread02h and sPLCfuncwrite0fh will
	 *  be passed to classMODCONTROL class.
	 */
	sPLCfuncread02h = cPLCfuncread02h.get_ModStruct(8);
	printf ("-----Read 02h PLC Modbus Function Class-----\n");
	printf (" function: %x\n", sPLCfuncread02h.Function);
	printf (" .SizeWords: %d\n", sPLCfuncread02h.SizeWords);
	printf (" get_AllBytes: %d\n", cPLCfuncread02h.get_AllBytes() );

	sPLCfuncwrite0fh = cPLCfuncwrite0fh.get_ModStruct(10);
	printf ("-----Write 0fh PLC Modbus Function Class-----\n");
	printf (" function: %x\n", sPLCfuncwrite0fh.Function);
	printf (" .SizeBytes: %d\n", sPLCfuncwrite0fh.SizeBytes);
	printf (" .SizeBits: %d\n", sPLCfuncwrite0fh.SizeBits);
	printf (" get_AllBytes: %d\n", cPLCfuncwrite0fh.get_AllBytes() );


	// *** TEST c_modcontrol class ***
	// -------------------------------

	/*
	 * setting IP Address
	 */
	const char * ipsplc = "172.16.17.100";
	cPLCmodcontrol.set_IPaddress(ipsplc);
	printf("----- ip address-----\n");
	printf("  PLC: %s \n", cPLCmodcontrol.get_IPaddress() );


	/*
	 * ReadModbus Message Modcontrol member function
	 */
	sizedata = sizeof(sPLCiomap.inputword);		// this needs to be in words not bytes.
	sPLCfuncread02h = cPLCfuncread02h.get_ModStruct(sizedata);
	sizemsg = cPLCfuncread02h.get_AllBytes();
	result = cPLCmodcontrol.ReadModbusMessage((char*)&sPLCfuncread02h, sizedata );
	printf("--- ReadModbusMessage -----\n");
	printf(" function message size: %d\n", sizemsg);
	printf(" read result: %d\n", result);


	/*
	 * WriteModbus Message Modcontrol member function
	 */
	sizedata = sizeof(sPLCiomap.outputword);
	sPLCfuncwrite0fh = cPLCfuncwrite0fh.get_ModStruct(sizedata);
	sizemsg = cPLCfuncwrite0fh.get_AllBytes();
	result = cPLCmodcontrol.WriteModbusMessage((char*)&sPLCfuncwrite0fh, sizemsg, (char*)&sPLCiomap.outputword, sizedata);
	printf("--- WriteModbusMessage -----\n");
	printf(" function message size: %d\n", sizemsg);
	printf(" function length: %d\n", sPLCfuncwrite0fh.Length);
	printf(" data size: %d\n", sizedata);
	printf(" write result: %d\n", result);



	// --- SICK READ ---
	//c_classMODCONTROL modsickcontrol;




	// *** TEST c_iocontrol class ***
	// ------------------------------

	cPLCio.Write_Set( horn );
	cPLCio.Write_Set(light);
	cPLCio.Write_Set(charger);
	cPLCio.Write_Set(brake);

	sPLCiomap = cPLCio.get_iomap();
	printf ("return from get_iomap(): %x\n", sPLCiomap.outputword[0]);

	cPLCio.Write_Rst( horn );
	cPLCio.Write_Rst(light);

	sPLCiomap = cPLCio.get_iomap();
	printf ("return from get_iomap(): %x\n", sPLCiomap.outputword[0]);





}
