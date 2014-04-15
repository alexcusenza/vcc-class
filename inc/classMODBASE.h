/*
 * classMODBASE.h
 *
 *  Created on: Mar 23, 2014
 *      Author: acusenza
 */

#ifndef CLASSMODBASE_H_
#define CLASSMODBASE_H_

// +--------------------------+
// 		classMODBASE
// +--------------------------+

class classMODBASE
{
public:
	classMODBASE();
	~classMODBASE() {};
	virtual void Write_Set(IONewType &) = 0;
	virtual void Write_Rst(IONewType &) = 0;
	virtual int ReadValue(IONewType &) = 0;

	virtual void Write_Field(IONewType &, int) = 0;

protected:


};

#endif /* CLASSMODBASE_H_ */
