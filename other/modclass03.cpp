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
	int result;
	// TEST c_modfunc class
	// ---------------------

	printf(" *** STARTING CLASS TEST *** \n");

	/*
	 * This class sets up the parameters and structures for the modbus function reads and writes
	 * It is intended to pass this to a structure using get_ModReadStruct() and pass to the next
	 * class c_ModControlClass
	 */

	// --- PLC READ / WRITE ---
	/*
	 *  Instantiate the first class for modplcread, which is the modbus function 02h protocol
	 *  modbus function 0fh write protocol
	 */
	c_ModFuncRead02h modplcread(dPlcUID, 0x1234, 0x0110);
	struct s_ModFuncRead02h s_modplcreadfunc;

	c_ModFuncWrite0Fh modplcwrite(dPlcUID, 0x1, 8, 0x1);
	struct s_ModFuncWrite0Fh s_modplcwritefunc;


	// --- SICK READ / WRITE ---
	//c_ModFuncWrite10h modsick(dSickUID, 1234, 5, 5);
	//struct s_ModFuncWrite10h s_modsickwritefunc;


	// --- PLC READ/WRITE calling getting structure ---
	/*
	 *  This modbus function protocol structure is passed to the c_Modbuscontrol class
	 *  via an array then using set_ReadMessage() function member.
	 */
	s_modplcreadfunc = modplcread.get_ModStruct();
	printf ("modplc read message function:  %x\n", s_modplcreadfunc.Function);

	/*
	 * 	Must call set_length(), need to figure how to automatically.  Sets the Length of the message
	 * 	which includes the data size which is entered into parameter list of class ModFuncWrite
	 * 	Also, any changes to the class, must then call get_modstruct to get copy of updated structure.
	 */
	modplcwrite.set_Length();
	s_modplcwritefunc = modplcwrite.get_ModStruct();
	printf ("modplc write message function:  %d\n", s_modplcwritefunc.Function);



	// *** TEST c_modcontrol class ***
	// -------------------------------

	// --- PLC READ / WRITE ---
	c_ModControlClass modplccontrol;

	/*
	 * setting IP Address
	 */

	const char * ipsplc = "172.16.17.100";
	modplccontrol.set_IPaddress(ipsplc);
	printf("ip address: %s \n", modplccontrol.get_IPaddress() );


	/*
	 * copy the read function 02h structure to a message buffer
	 */

	int sizebuf = sizeof(s_modplcreadfunc);
	char modplcreadbuffer[sizebuf];
	memset(modplcreadbuffer, 0, sizebuf);
	memcpy(&modplcreadbuffer, (char*)&s_modplcreadfunc, sizebuf);

	printf("s_modplcreadfunc structure size: %d\n", sizebuf);
	printf("s_modplcreadfunc length: %d\n", s_modplcreadfunc.Length);

	for (int i=0; i<sizebuf; i++)
	{
		printf("[%d]:%x ", i, modplcreadbuffer[i]);
	}
	cout << endl;

	/*
	 *  setup READ: use the set_HeaderMessage to copy the above buffer
	 */

	modplccontrol.set_HeaderMessage(modplcreadbuffer);

	result = modplccontrol.ReadModbusMessage();
	printf("readmodbus message result: %d\n", result);



	/*
	 * copy the write function 0fh structure to message buffer
	 */

	sizebuf = sizeof(s_modplcwritefunc);
	char * modplcwritebuffer[sizebuf];
	memset(modplcwritebuffer,0,sizebuf);
	memcpy(&modplcwritebuffer, (char*)&s_modplcwritefunc, sizebuf);

	printf("s_modplcwritefunc structure size: %d\n", sizebuf);
	printf("s_modplcwritefunc length: %d\n", s_modplcwritefunc.Length);


	/*
	 * setup WRITE: use set_HeaderMessage to
	 */

	modplccontrol.set_HeaderMessage(modplcwritebuffer);
	char data[] = {1,2,3,4,5,6};
	modplccontrol.set_DataMessage(data);

	result = modplccontrol.WriteModbusMessage();
	printf("writemodbus message result: %d\n", result);


	// --- SICK READ ---
	//c_ModControlClass modsickcontrol;



	// *** TEST c_iocontrol class ***
	// ------------------------------

	c_IOControl plcio;
	struct IOMapType s_plciomap;

	plcio.Write_Set( horn );
	plcio.Write_Set(light);
	plcio.Write_Set(charger);
	plcio.Write_Set(brake);

	s_plciomap = plcio.get_iomap();
	printf ("return from get_iomap(): %x\n", s_plciomap.outputword[0]);

	plcio.Write_Rst( horn );
	plcio.Write_Rst(light);

	s_plciomap = plcio.get_iomap();
	printf ("return from get_iomap(): %x\n", s_plciomap.outputword[0]);

}
