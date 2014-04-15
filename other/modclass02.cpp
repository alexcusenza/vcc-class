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
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 502
#define dPlcUID 0
#define dSickUID 1
const char * ips = "172.16.17.75";

/*
 * Structure
 * defining the Modbus ReadMessage Format
 */
struct s_ModBus_ReadMessageType
{
	int TransID;
	int ProtoID;
	int Length;
	int UnitID;
	int Function;
	int Address;
	int SizeBytes;
	int MsgByteCount;

};

struct s_ModBus_WriteMessageType
{
	int TransID;
	int ProtoID;
	int Length;
	int UnitID;
	int Function;
	int StartAddr;
	int SizeBytes;
	int *DataMsg;

	int MsgSize;
	int MsgByteCount;
};

/*
 *  Class Definition : Base
 *  -----------------------
 *  c_ModbusReadMessage
 *  implementation of MODBUS ReadMessage
 */
class c_ModbusReadMessage
{
public:
	c_ModbusReadMessage (int a);

	//int get_Messize() {
	//	return (s_Mod_ReadMsg.MessSize);
	//}

	//int get_ByteCount() {
	//	return (s_Mod_ReadMsg.ByteCount);
	//}

	int get_Length() {
		return (s_Mod_ReadMsg.Length);
	}

	void set_Length (int length) {
		s_Mod_ReadMsg.Length = length;
	}

	int get_UnitID() {
		return (s_Mod_ReadMsg.UnitID);
	}

	void set_UnitID (int unitid) {
		s_Mod_ReadMsg.UnitID = unitid;
	}

	int get_FuncID() {
		return (s_Mod_ReadMsg.Function);
	}

	void set_FuncID(int function) {
		s_Mod_ReadMsg.Function = function;
	}

	int get_TransCnt() {

		return (sizeof(s_Mod_ReadMsg.UnitID) + sizeof(s_Mod_ReadMsg.Function) + sizeof(s_Mod_ReadMsg.Address));
	}
	//get_Address();
	//set_Address();
	//get_SizeBytes();
	//set_SizeBytes();

	//void set_DataMsg(int &Data){
	//	s_Mod_ReadMsg.DataMsg = &Data;
	//}



protected:
	struct s_ModBus_ReadMessageType s_Mod_ReadMsg;

};

/*
 * class constructor
 */
c_ModbusReadMessage::c_ModbusReadMessage (int a)
{
	s_Mod_ReadMsg.TransID = 0;
	s_Mod_ReadMsg.ProtoID = 0;
	s_Mod_ReadMsg.UnitID = a;

	cout << "c_ModbusReadMessage created, Unit ID: " << a << endl;

}


/*
 * Class Definition : Derived
 * --------------------------
 * c_classMODCONTROL
 *
 */

class c_classMODCONTROL : public c_ModbusReadMessage
{

public:
	c_classMODCONTROL(int);

	int OpenSocket();
	int ConnectSocket();
	int ReadModbusMessage();
	int WriteModbusMessage();

private:
	struct sockaddr_in s_SocketName;
	int socketID;
	int error;

};

/*
 * Constructor Definition with a Parent/Child Class
 * ChildClass::ChildClass(int a, int b) : ParentClass(a, b)
 *
 */

c_classMODCONTROL::c_classMODCONTROL (int a) : c_ModbusReadMessage(a)
{
	cout << "c_classMODCONTROL Created" << endl;
	socketID = 0;
	error = 0;
}

int c_classMODCONTROL::OpenSocket()
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

int c_classMODCONTROL::ConnectSocket()
{
	error = connect(socketID, (struct sockaddr*) &s_SocketName, sizeof(s_SocketName));

	if (error < 0)
		return (errno);
	else
		return (0);
}

int c_classMODCONTROL::ReadModbusMessage(void)
{


	return 0;
}

int c_classMODCONTROL::WriteModbusMessage(void)
{

	return 0;
}




/*
 * MAIN PROGRAM
 * ------------
 */

int main(void)
{
	c_ModbusReadMessage modtest(dPlcUID);
	c_ModbusReadMessage modtemp(dSickUID);
	c_classMODCONTROL modcontrol1(2);

	modcontrol1.set_FuncID(10);

	modtest.set_Length(4);
	modtemp.set_Length(2);

	//modtest.get_Length();

	cout << "modtemp message byte length: " << modtemp.get_Length() << endl;
	cout << "modbus message byte length: " << modtest.get_Length() << endl;
	cout << "modcontrol function id: " << modcontrol1.get_FuncID() << endl;


}
