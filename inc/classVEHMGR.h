/*
 * classVEHMGR.h
 *
 *  Created on: May 3, 2014
 *      Author: acusenza
 */

#ifndef CLASSVEHMGR_H_
#define CLASSVEHMGR_H_

class classVEHMGR
{
public:

	classVEHMGR();
	void PushButton();
	void Lights();
	void Horn();
	void HoldStop();
	void Battery();

private:
	int Destination;
	int Location;
	int Operation;
	int FloorCode;
	int CVS;
	int Direction;
	bool Released;
	bool AutoOn;
	bool Charging;
};



#endif /* CLASSVEHMGR_H_ */
