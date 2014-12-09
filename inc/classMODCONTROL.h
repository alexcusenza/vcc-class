/*
 * classMODCONTROL.h
 *
 *  Created on: Mar 23, 2014
 *      Author: acusenza
 */

#ifndef CLASSMODCONTROL_H_
#define CLASSMODCONTROL_H_

#include "classMODREGISTER.h"

// +------------------------------------+
// 		classMODCONTROL: CLASS
// +------------------------------------+

/*
 * classMODCONTROL
 * 	- Derived from classMODREGISTER
 * 	- Derived from classMODBASE
 *
 * 	Class to setup connection modbus sockets
 */

class classMODCONTROL: public classMODREGISTER
{

public:
	classMODCONTROL(int);
	~classMODCONTROL();

	void set_IPaddress(const char *);
	const char * get_IPaddress();

	int OpenSocket();
	int get_Socket();
	int ConnectSocket();
	int CloseSocket();

	void setReadModbusHeader(char *, int);
	void setWriteModbusHeader(char *, int);
	void setWriteModbusData(char *, int);

	int ReadModbusMessage();
	int WriteModbusMessage();
	int ReadModbusResponse();
	int WriteModbusReponse();

	int get_ReadBuffer();

	//struct MODdataType sMODdata;

protected:
	int mDevice;
	char m_DevName[32];

private:

	int m_socket;
	int error;
	const char * m_ips;

	char * readheadermsg;
	int readheadersize;
	char * writeheadermsg;
	int writeheadersize;
	char * writedatamsg;
	int writedatasize;

	char * readbuffer[128];
	char * writebuffer[128];

};


#endif /* CLASSMODCONTROL_H_ */
