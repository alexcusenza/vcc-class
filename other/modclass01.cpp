/*
 * modclass01.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: acusenza
 */


/*
 * attempt to implement a structure and a class
 */

#include <iostream>
using namespace std;

/*
 * Structure
 * defining the Modbus ReadMessage Format
 */
struct s_ModBus_ReadMessageType
{
	int MessSize;
	int ByteCount;
	int TransID;
	int ProtoID;
	int Length;
	int UnitID;
	int Function;
	int Address;
	int SizeBytes;
};

/*
 *  Class
 *  implementation of MODBUS ReadMessage
 */
class c_ModbusReadMessage{
public:
	c_ModbusReadMessage(int a);

	int get_Messize() {
		return (s_Mod_ReadMsg.MessSize);
	}

	int get_ByteCount() {
		return (s_Mod_ReadMsg.ByteCount);
	}

	int get_Length() {
		return (s_Mod_ReadMsg.Length);
	}

	void set_Length( int length) {
		s_Mod_ReadMsg.Length = length;
	}

	int get_UnitID() {
		return (s_Mod_ReadMsg.UnitID);
	}

	void set_UnitID( int unitid) {
		s_Mod_ReadMsg.UnitID = unitid;
	}

	int get_FuncID() {
		return (s_Mod_ReadMsg.Function);
	}

	void set_FuncID(int function) {
		s_Mod_ReadMsg.Function = function;
	}

	//get_Address();
	//set_Address();
	//get_SizeBytes();
	//set_SizeBytes();

private:
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

	cout << "object created, unit id " << a << endl;
}


/*
 * MAIN
 * ----
 */

int main(void)
{

#define dPlcUID 0
#define dSickUID 1

	c_ModbusReadMessage modtest(dPlcUID);
	c_ModbusReadMessage modtemp(dSickUID);

	modtest.set_Length(4);
	modtemp.set_Length(2);

	//modtest.get_Length();

	cout << "modtemp message byte length: " << modtemp.get_Length() <<endl;
	cout << "modbus message byte length: " << modtest.get_Length() <<endl;


}
