/*
 * hmistruct.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: acusenza
 */

typedef struct VMtoHMIMapType
{
	int *VMptrMap;
	bool ByteSwap;
	int numWords;

};

enum eHMIdatatype
{
	tbit,
	tchar,
	tbyte,
	tword
};


void main (void)
{
	static VMtoHMIMapType sVMtoHMI_Map[] =
	{
			(int*)&FileDataptr->FileInfo16[0].Month, 			tbyte, 		1,			// 2120
			(int*)&FileDataptr->FileInfo16[0].Day, 				tbyte, 		1,			// 2121
			(int*)&FileDataptr->FileInfo16[0].Year, 			tbyte, 		1,			// 2122
			(int*)&FileDataptr->FileInfo16[0].Hour, 			tbyte, 		1,			// 2123
			(int*)&FileDataptr->FileInfo16[0].Minute, 			tbyte, 		1,			// 2124
			(int*)&FileDataptr->FileInfo16[0].FileSize, 		tbyte, 		1,			// 2125
			(int*)&FileDataptr->FileInfo16[0].Version, 			tbyte, 		1,			// 2126
			(int*)&FileDataptr->FileInfo16[0].SubVersion,		tbyte, 		1,			// 2127
			(int*)&FileDataptr->FileInfo16[0].filename, 		tchar, 		14/2,		// 2128 + 7

			(int*)&FileDataptr->FileInfo16[1].Month, 			tbyte, 		1,			// 2135
			(int*)&FileDataptr->FileInfo16[1].Day, 				tbyte, 		1,			// 2136
			(int*)&FileDataptr->FileInfo16[1].Year, 			tbyte, 		1,			// 2137
			(int*)&FileDataptr->FileInfo16[1].Hour, 			tbyte, 		1,			// 2138
			(int*)&FileDataptr->FileInfo16[1].Minute, 			tbyte, 		1,			// 2139
			(int*)&FileDataptr->FileInfo16[1].FileSize, 		tbyte, 		1,			// 2140
			(int*)&FileDataptr->FileInfo16[1].Version, 			tbyte, 		1,			// 2141
			(int*)&FileDataptr->FileInfo16[1].SubVersion,		tbyte, 		1,			// 2142
			(int*)&FileDataptr->FileInfo16[1].filename, 		tchar, 		14/2,		// 2143 + 7

			(int*)&FileDataptr->FileInfo16[2].Month, 			true, 		1,			// 2150
			(int*)&FileDataptr->FileInfo16[2].Day, 				true, 		1,			// 2151
			(int*)&FileDataptr->FileInfo16[2].Year, 			true, 		1,			// 2152
			(int*)&FileDataptr->FileInfo16[2].Hour, 			true, 		1,			// 2153
			(int*)&FileDataptr->FileInfo16[2].Minute, 			true, 		1,			// 2154
			(int*)&FileDataptr->FileInfo16[2].FileSize, 		true, 		1,			// 2155
			(int*)&FileDataptr->FileInfo16[2].Version, 			true, 		1,			// 2156
			(int*)&FileDataptr->FileInfo16[2].SubVersion,		true, 		1,			// 2157
			(int*)&FileDataptr->FileInfo16[2].filename, 		false, 		14/2,		// 2158 + 7

			(int*)&FileDataptr->FileInfo16[3].Month, 			true, 		1,			// 2165
			(int*)&FileDataptr->FileInfo16[3].Day, 				true, 		1,			// 2166
			(int*)&FileDataptr->FileInfo16[3].Year, 			true, 		1,			// 2167
			(int*)&FileDataptr->FileInfo16[3].Hour, 			true, 		1,			// 2168
			(int*)&FileDataptr->FileInfo16[3].Minute, 			true, 		1,			// 2169
			(int*)&FileDataptr->FileInfo16[3].FileSize, 		true, 		1,			// 2170
			(int*)&FileDataptr->FileInfo16[3].Version, 			true, 		1,			// 2171
			(int*)&FileDataptr->FileInfo16[3].SubVersion,		true, 		1,			// 2172
			(int*)&FileDataptr->FileInfo16[3].filename, 		false, 		14/2,		// 2173 + 7

			(int*)&FileDataptr->FileInfo16[4].Month, 			true, 		1,			// 2180
			(int*)&FileDataptr->FileInfo16[4].Day, 				true, 		1,			// 2181
			(int*)&FileDataptr->FileInfo16[4].Year, 			true, 		1,			// 2182
			(int*)&FileDataptr->FileInfo16[4].Hour, 			true, 		1,			// 2183
			(int*)&FileDataptr->FileInfo16[4].Minute, 			true, 		1,			// 2184
			(int*)&FileDataptr->FileInfo16[4].FileSize, 		true, 		1,			// 2185
			(int*)&FileDataptr->FileInfo16[4].Version, 			true, 		1,			// 2186
			(int*)&FileDataptr->FileInfo16[4].SubVersion,		true, 		1,			// 2187
			(int*)&FileDataptr->FileInfo16[4].filename, 		false, 		14/2,		// 2188 + 7

			(int*)&FileDataptr->FileInfo32.Month, 				true, 		1,			// 2195
			(int*)&FileDataptr->FileInfo32.Day, 				true, 		1,			// 2196
			(int*)&FileDataptr->FileInfo32.Year, 				true, 		1,			// 2197
			(int*)&FileDataptr->FileInfo32.Hour, 				true, 		1,			// 2198
			(int*)&FileDataptr->FileInfo32.Minute, 				true, 		1,			// 2199
			(int*)&FileDataptr->FileInfo32.FileSize, 			true, 		2,			// 2200
			(int*)&FileDataptr->FileInfo32.Version, 			true, 		1,			// 2202
			(int*)&FileDataptr->FileInfo32.SubVersion,			true, 		1,			// 2203
			(int*)&FileDataptr->FileInfo32.filename, 			false, 		14/2		// 2204 + 7

	};

	int sVMtoHMI_MapSize = sizeof(sVMtoHMI_Map)/sizeof(VMtoHMIMapType);





	// ********************************************************************
	for (int8u i = 0; i < VMtoHMIsize ; i++)
	{
		VMGlobalptr->HMITransferTest[i] = *VMtoHMIMap[i];
	}
	// ********************************************************************

	int8u *r;
	int16u *s;
	int16u tempsize = 0;
	int i, j;
	// ---------------------------------------------
	// VMtoHMIMapType s;
	// s.VMptrMap = (int16u*) &sHMIMapTest[i].VMptrMap;
	// *(r++) = ( (*s.VMptrMap & 0xff00) >> 8);
	// ----------------------------------------------

	r = (int8u*)&VMtoHMI_TxBuffer;

	for ( i = 0; i< sVMtoHMI_MapSize; i++ )
	{
		s = sVMtoHMI_Map[i].VMptrMap;

		// SWAP THE BYTES
		if ( sVMtoHMI_Map[i].ByteSwap == true )
		{
			for (j = 0; j < sVMtoHMI_Map[i].numWords; j++ )
			{
				*(r++) = (*s & 0xFF00) >> 8;
				*(r++) = *s & 0x00FF;
				s++;
				tempsize++;
			}
		}
		// DO NOT SWAP, MOST LIKELY TEXT
		else
		{
			for (j = 0; j < sVMtoHMI_Map[i].numWords; j++ )
			{
				*(r++) = *s & 0x00FF;
				*(r++) = (*s & 0xFF00) >> 8;
				s++;
				tempsize++;
			}
		}
	}

	VMtoHMI_TxCnt = tempsize;




}
