/*
 * modcontrol.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: acusenza
 */

#include <iostream>
#include <string.h>
#define PORT 502


/*
 * Class Definition : Derived
 * --------------------------
 * ModControlClass
 *
 */

class ModControlClass
{
public:
	ModControlClass();
	void set_IPaddress(const char *);
	const char * get_IPaddress();
	int OpenSocket();
	int ConnectSocket();

	int ReadModbusMessage(char *, int);
	int WriteModbusMessage(char *, int, char *, int);
	int ReadModbusResponse();
	int WriteModbusReponse();

private:

	struct sockaddr_in s_SocketName;
	int socketID;
	int error;
	const char * ips;
};

/*
 * Constructor Definition
 */

ModControlClass::ModControlClass()
{
	cout << "ModControlClass Created" << endl;
	socketID = 0;
	error = 0;

}

void ModControlClass::set_IPaddress (const char * iptmp)
{
	ips = iptmp;
}

const char * ModControlClass::get_IPaddress()
{
	return (ips);
}

int ModControlClass::OpenSocket()
{
	socketID = socket(AF_INET, SOCK_STREAM, 0); 			// Create the stream socket

	if (socketID < 0)
		return (errno);
	else
	{
		memset (&s_SocketName, 0, sizeof(s_SocketName));   		// Initialize the structure to zero
		s_SocketName.sin_family = AF_INET;            			// Address family is AF_INET
		s_SocketName.sin_port = htons(PORT);          			// Assign our port number in network byte order
		s_SocketName.sin_addr.s_addr = inet_addr(ips);

		return (0);
	}
}

int ModControlClass::ConnectSocket()
{
	error = connect(socketID, (struct sockaddr*) &s_SocketName, sizeof(s_SocketName));

	if (error < 0)
		return (errno);
	else
		return (0);
}

int ModControlClass::ReadModbusMessage(char *message, int msgsize)
{
	error = send(socketID, &message, msgsize, 0);
	return (1);
}

int ModControlClass::WriteModbusMessage(char *message, int msgsize, char *data, int datasize)
{
	error = send(socketID, &message, msgsize, 0);
	error = send(socketID, &data, datasize, 0);

	return (1);
}

int ModControlClass::ReadModbusResponse()
{
	/*
	 * receive and parse the incoming data
	 */
	return 0;
}


int ModControlClass::WriteModbusReponse()
{
	/*
	 * To indicate a WriteModbusMessage has completed and commence a read
	 * and also used to capture an error from a writemodbusmessage
	 */
	return 0;
}
