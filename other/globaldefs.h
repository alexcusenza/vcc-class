/*
 * globaldefs.h
 *
 *  Created on: Mar 7, 2014
 *      Author: acusenza
 */

#ifndef GLOBALDEFS_H_
#define GLOBALDEFS_H_

enum eDirType
{
	IN,
	OUT
};

struct IOType
{
	eDirType eDir;
	int Word;
	int Bit;
	int Width;
};

struct IOMapType
{
	short outputword[8];
	short inputword[8];

};



#endif /* GLOBALDEFS_H_ */
