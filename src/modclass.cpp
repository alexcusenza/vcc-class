/*
 * modclass.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: acusenza
 */

using namespace std;

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

// ******* CLASSES ************
#include "../inc/classMODFUNC.h"
#include "../inc/classMODCONTROL.h"
#include "../inc/classMODREGISTER.h"
#include "../inc/classSIGNALHMI.h"
#include "../inc/classSIGNALIO.h"
//#include "../inc/classMODBASE.h"
#include "../inc/classVEHMGR.h"

// ******* DEFINITIONS *********
#include "../inc/defsGLOBAL.h"
//#include "../inc/defsIOTYPE.h"
//#include "../inc/defsFUNCS.cpp"
//#include "../inc/defsHMIinputs.h"


// ***** CONSTANTS *****

#define dPLCuid 0
#define dSICKuid 1

const char * ipPLC = "172.16.17.75";
const char * ipSICK0 = "172.16.17.50";

//#define connect
//#define select

/* ******************************************************
 * MAIN PROGRAM
 * ******************************************************
 */


// ***************************
// 		MAIN PROGRAM
// ***************************

int main(void)
{
	//int error, result;
	//int sizemsg;
	//int sizedata;


	classVEHMGR * cVMSystem;
	cVMSystem = new classVEHMGR;

	cVMSystem->PushButton();


#if defined (all)
	// +----MODBUS FUNCTION READ/WRITE CLASS & STRUCTURE SETUP-----+
	/*
	 *
	 */
	classModFuncRead02h cPLCfuncread02h(dPLCuid, 0x1122);
	struct ModFuncRead02hType sPLCfuncread02h;

	classModFuncWrite0Fh cPLCfuncwrite0fh(dPLCuid, 0x3344);
	struct ModFuncWrite0FhType sPLCfuncwrite0fh;

	//classModFuncRead03h cSICK0funcread03h(dSICKuid, 0x044b);
	//struct ModFuncRead03hType sSICK0funcread03h;

	//classModFuncWrite10h cSICK0funcwrite10h(dSICKuid, 0x0833);
	//struct ModFuncWrite10hType sSICK0funcwrite10h;

	// +------------------------------------+
	// 		CLASS DECLARATION
	// +------------------------------------+


//	classMODCONTROL * cpMODdev[MaxDev];
//	cpMODdev[PLC] = new classMODCONTROL(PLC);
//	cpMODdev[SICK0] = new classMODCONTROL(SICK0);
//
//	classMODCONTROL * cpMODhmi;
//	cpMODhmi = new classMODCONTROL(2);
//
//
//	classSIGNALHMI * cpHMIsig[5];
//	cpHMIsig[0] = new classSIGNALHMI(cpMODhmi, hAutoStart);
//	cpHMIsig[1] = new classSIGNALHMI(cpMODhmi, hDestination);
//
//	classSIGNALHMI * phAutoStart = new classSIGNALHMI(cpMODhmi, hAutoStart);
//	classSIGNALHMI * phDestination = new classSIGNALHMI(cpMODhmi, hDestination);
//
//	classSIGNALIO * pioESTOP = new classSIGNALIO(cpMODdev[PLC], ioESTOP);
//	classSIGNALIO * pioSTART = new classSIGNALIO(cpMODdev[PLC], ioSTART);
//	classSIGNALIO * pioCRM = new classSIGNALIO(cpMODdev[PLC], ioCRM);



	cpHMIsig[0]->checkstate();
	phAutoStart->checkstate();
	pioESTOP->readvalue();
	pioCRM->write_set();


	// +------------------------------------+
	// 		SOCKET OPEN / CONNECTION
	// +------------------------------------+
	/*
	 * Open and Connection to Sockets
	 */
	printf("****** Socket Open/Connect ******\n");

	cpMODdev[PLC]->set_IPaddress(ipPLC);
	printf("IP ADDRESS %d: %s \n", PLC, cpMODdev[PLC]->get_IPaddress() );

	cpMODdev[PLC]->OpenSocket();
	printf("socket opened - id: %d\n", cpMODdev[PLC]->get_Socket() );

	cpMODdev[SICK0]->set_IPaddress(ipSICK0);
	printf("IP ADDRESS %d: %s \n", SICK0, cpMODdev[SICK0]->get_IPaddress() );

	cpMODdev[SICK0]->OpenSocket();
	printf("socket opened - id: %d\n", cpMODdev[SICK0]->get_Socket() );


#if defined (connect)
	error = cptrModControl[PLC].ConnectSocket();

	printf("sleeping... \n");
	sleep(3);
#endif

	// +------------------------------------+
	// 		READMODBUS / WRITEMODBUS MESSAGE
	// +------------------------------------+
	/*
	 * ReadModbus Message Modcontrol member function
	 */

	//sizedata = sizeof(sPLCiomap.inputword);		// this needs to be in words not bytes.
	//sizedata = sizeof(sIOmap[PLC].inputword);
	sPLCfuncread02h = cPLCfuncread02h.get_ModStruct(4);
	sizemsg = cPLCfuncread02h.get_MsgByteCnt();
	cpMODdev[PLC]->setReadModbusHeader((char*) &sPLCfuncread02h, sizemsg);
	printf("****** READ MODBUS MESSAGE ******\n");
	printf("> function message size: %d\n", sizemsg);


	// Printing out funcread structure
	/*
	 * printing out structure in array to see order of bytes
	 */
	sPLCfuncread02h = cPLCfuncread02h.get_ModStruct(6);
	int sizebuf = sizeof(sPLCfuncread02h);
	char tempbuffer[sizebuf];
	memset(tempbuffer, 0, sizebuf);
	memcpy(tempbuffer, (char*)&sPLCfuncread02h, sizebuf);
	printf("****** FUNCTION MESSAGE BUFFER ******\n");
	printf("> ");
	for (int i=0; i<sizebuf; i++)
	{
		printf("[%d]:%x ", i, tempbuffer[i]);
	}
	printf("\n");

	/*
	 * WriteModbus Message Modcontrol member function
	 */
	//sizedata = sizeof(sPLCiomap.outputword);
	//sizedata = sizeof(sIOmap[PLC].outputword);
	sPLCfuncwrite0fh = cPLCfuncwrite0fh.get_ModStruct(4);
	sizemsg = cPLCfuncwrite0fh.get_MsgByteCnt();
	cpMODdev[PLC]->setWriteModbusHeader((char *) &sPLCfuncwrite0fh, sizemsg);
	cpMODdev[PLC]->setWriteModbusData((char *) &data, sizedata);

	printf("****** WRITE MODBUS MESSAGE ******\n");
	printf("> function message size: %d\n", sizemsg);
	printf("> function length: %d\n", sPLCfuncwrite0fh.Length);
	//printf("> data size: %d\n", sizedata);


	// +------------------------------------+
	// 		SELECT SETUP
	// +------------------------------------+

#if defined(select)
	int i ;
	bool connected = true;
	int command, step;

	fd_set rfds, wfds;
	timeval timeout;

	command = readcmd;
	step = 1;

	printf("****** SELECT CONTROL ******\n");
	while (connected)
	{
		FD_ZERO(&rfds);
		FD_ZERO(&wfds);

		/*
		 * setup the file descriptor mask to select on either
		 * read or write based on the command.  When select is
		 * called, it will wait either on only read or write.
		 *
		 * Locked step so that all devices will perform the same
		 * operation.
		 */
		for (i=0;i<MaxDev;i++)
		{
			if (command == readresp || command == writeresp)
				FD_SET(cpMODdev[i]->get_Socket(), &rfds);

			else if (command == readcmd || command == writecmd)
				FD_SET(cpMODdev[i]->get_Socket(), &wfds);
		}

		timeout.tv_sec = 1;
		timeout.tv_usec = 0;

		/*
		 * Select statement
		 */
		if (select(MaxDev, &rfds, &wfds, NULL, &timeout) <= 0)
		{
			printf("errno #: %d \n", errno);
			connected = false;
		}
		else
		{
			//printf("selecting???? command: %d\n", command);

			/*
			 * Cycle through all devices available and check sockets
			 * for data either to read or be written, again based on the
			 * command state.
			 *
			 * Read rfds: read modbus data read/write response
			 * Write wfds: send modbus data read/write message
			 */
			for (i=0; i<MaxDev; i++)
			{
				if ( FD_ISSET(cpMODdev[i]->get_Socket(), &rfds))
				{
					if (command == readresp)
					{
						printf("read response\n");
						//cpMODdev[i]->ReadModbusResponse();
					}
					else if (command == writeresp)
					{
						printf("write response\n");
						//cpMODdev[i]->WriteModbusReponse();
					}

					//FD_CLR(cptrModControl[i]->get_Socket(), &rfds);

				}
				else if (FD_ISSET(cpMODdev[i]->get_Socket(), &wfds))
				{
					if (command == readcmd)
					{
						printf("socket %d: read command [%d]\n",cpMODdev[i]->get_Socket(),i);
						//cpMODdev[i]->ReadModbusMessage();
					}
					else if (command == writecmd)
					{
						//cpMODdev[i]->setWriteModbusData((char*)&sIOmap[i].outputword, sizeof(sIOmap[i].outputword) );
						printf("write command\n");
						//cpMODdev[i]->WriteModbusMessage();
					}

					//FD_CLR(cpMODdev[i]->get_Socket(), &wfds);
				}
			}


			/*
			 * Switch-Case state machine to cycle through states:
			 * readcmd = send read command
			 * readresp = receive read response
			 * writecmd = send write command
			 * writeresp = receive write response
			 */

			switch(step)
			{
			case 1:
			{
				command = readcmd;
				step = 2;
				break;
			}
			case 2:
			{
				command = readresp;
				step = 3;
				break;
			}
			case 3:
			{
				command = writecmd;
				step = 4;
				break;
			}
			case 4:
			{
				command = writeresp;
				step = 1;
				break;
			}

			}
		}
	}
#endif

	// +------------------------------------+
	// 		INPUT / OUTPUT CONTROL CLASS
	// +------------------------------------+

	printf("****** IO Output Set/Rst ******\n");

	bool toggle = true;

	for (int i=0; i<3; i++)
	{
		if (toggle)
		{
			fIO_writeset(ioCRM, cpMODdev);
			fIO_writeset(ioHORN, cpMODdev);
			fIO_writerst(ioSICKCRM, cpMODdev);
			fIO_writerst(ioSICKHORN, cpMODdev);

			fIO_writefield(ioOUTBYTE1, 5, cpMODdev);
			fIO_writefield(ioOUTBYTE2, 4, cpMODdev);

			toggle = false;
		}
		else
		{
			fIO_writerst(ioCRM, cpMODdev);
			fIO_writerst(ioHORN, cpMODdev);
			fIO_writeset(ioSICKCRM, cpMODdev);
			fIO_writeset(ioSICKHORN, cpMODdev);

			fIO_writefield(ioOUTBYTE1, 1, cpMODdev);
			fIO_writefield(ioOUTBYTE2, 1, cpMODdev);

			toggle = true;
		}

		printf ("PLC - get_iomap: %x\n", cpMODdev[PLC]->get_iomap().outword[0]);
		printf ("PLC - iomap word field: %x\n", cpMODdev[PLC]->get_iomap().outword[1]);
		printf ("SICK - get_iomap: %x\n", cpMODdev[SICK0]->get_iomap().outword[0]);
		sleep(1);
	}


	// +------------------------------------+
	// 		HMI Control
	// +------------------------------------+

	delete cpMODdev[PLC];
	delete cpMODdev[SICK0];
#endif

}
