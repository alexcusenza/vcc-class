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
	virtual ~classMODBASE() {};
	//virtual void Write_Set(IODefType &) = 0;
	//virtual void Write_Rst(IODefType &) = 0;
	virtual void WriteValue(IODefType &, eSetRstType) = 0;
	virtual int ReadValue(IODefType &) = 0;

	virtual void Write_Field(IODefType &, int) = 0;

protected:


};

#endif /* CLASSMODBASE_H_ */
