/*
 * modcontrol.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory.h>
#include <fcntl.h>

#include "classMODCONTROL.h"
#include "defsGLOBAL.h"

#define PORT 502

// +------------------------------------+
// 		CONSTRUCTOR
// +------------------------------------+


classMODCONTROL::classMODCONTROL(int Device):
				classMODREGISTER(Device)
{
	mDevice = Device;

	sprintf(m_DevName,"Dev#%d",Device);
	printf("classMODCONTROL Created: %s\n", m_DevName);
}

// +------------------------------------+
// 		DESTRUCTOR
// +------------------------------------+

classMODCONTROL::~classMODCONTROL()
{
	printf("classMODCONTROL Destroyed: %s\n", m_DevName);
}


// +------------------------------------+
// 		set_IPaddress
// +------------------------------------+

void classMODCONTROL::set_IPaddress (const char * iptmp)
{
	m_ips = iptmp;
}

// +------------------------------------+
// 		get_IPaddress
// +------------------------------------+

const char * classMODCONTROL::get_IPaddress()
{
	return (m_ips);
}

// +------------------------------------+
// 		OpenSocket
// +------------------------------------+

int classMODCONTROL::OpenSocket()
{
	struct sockaddr_in sSockName;

	m_socket = socket(AF_INET, SOCK_STREAM, 0); 			// Create the stream socket

	if (m_socket < 0)
	{
		printf("socket open error - errno: %d\n", errno);
		return -1;
	}
	else
	{
		memset (&sSockName, 0, sizeof(sSockName));   		// Initialize the structure to zero
		sSockName.sin_family = AF_INET;            			// Address family is AF_INET
		sSockName.sin_port = htons(PORT);          			// Assign our port number in network byte order
		sSockName.sin_addr.s_addr = inet_addr(m_ips);

		fcntl(m_socket, FNONBLOCK, FNDELAY);

		//error = connect(m_socket, (struct sockaddr*) &sSockName, sizeof(sSockName));
		if (error < 0)
		{
			printf("socket connect error - errno: %d\n", errno);
			return -1;
		}
		else
			printf("socket connected\n");


		return (0);
	}
}

// +------------------------------------+
// 		get_Socket
// +------------------------------------+

int classMODCONTROL::get_Socket()
{
	return (m_socket);
}


// +------------------------------------+
// 		ConnectSocket
// +------------------------------------+
int classMODCONTROL::ConnectSocket()
{

	return 0;
}

// +------------------------------------+
// 		setReadModbusHeader
// +------------------------------------+

void classMODCONTROL::setReadModbusHeader(char *message, int msgsize)
{
	readheadermsg = (char *)&message;
	readheadersize = msgsize;
}

// +------------------------------------+
// 		setWriteModbusHeader
// +------------------------------------+

void classMODCONTROL::setWriteModbusHeader(char *message, int msgsize)
{
	writeheadermsg = (char *)&message;
	writeheadersize = msgsize;
}

// +------------------------------------+
// 		setWriteModbusData
// +------------------------------------+

void classMODCONTROL::setWriteModbusData(char *message, int msgsize)
{
	writedatamsg = (char *) get_iomap().outword;
	writedatamsg = (char *)&message;
	writedatasize = sizeof (get_iomap().outword);
	writedatasize = msgsize;
}

// +------------------------------------+
// 		ReadModbusMessage
// +------------------------------------+

int classMODCONTROL::ReadModbusMessage()
{
	error = send(m_socket, &readheadermsg, readheadersize, 0);
	if (error <= 0)
	{
		printf("Error: ReadModbusMessage Send\n");
		return -1;
	}
	return 0;
}

// +------------------------------------+
// 		WriteModbusMessage
// +------------------------------------+

int classMODCONTROL::WriteModbusMessage()
{
	error = send(m_socket, &writeheadermsg, writeheadersize, 0);
	if (error <= 0)
	{
		printf("Error: WriteModbusMessage Send\n");
		return -1;
	}

	error = send(m_socket, &writedatamsg, writedatasize, 0);
	if (error <= 0)
	{
		printf("error\n");
		return -1;
	}

	return 0;
}


// +------------------------------------+
// 		ReadModbusResponse
// +------------------------------------+

int classMODCONTROL::ReadModbusResponse()
{
	error = read(m_socket, (char*)&readbuffer, sizeof(readbuffer));
	if (error <= 0)
	{
		printf("Error: ReadModbusResponse Read\n");
		return -1;
	}
	return 0;
}

//int classMODCONTROL::get_ReadBuffer()
//{
//	return (this->buffer);
//}

int classMODCONTROL::WriteModbusReponse()
{
	error = read(m_socket, (char*)&writebuffer, sizeof(writebuffer));
	if (error <= 0)
	{
		printf("Error: WriteModbusResponse Read\n");
		return -1;
	}
	return 0;
}
