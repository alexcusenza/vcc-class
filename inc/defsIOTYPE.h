/*
 * iodefs.h
 *
 *  Created on: Mar 7, 2014
 *      Author: acusenza
 */

#ifndef DEFSIOTYPE_H_
#define DEFSIOTYPE_H_

#include "defsGLOBAL.h"
#define numESTOPs 4
#define numLASERs 6
#define	numLIGHTs 6
#define numHORNs 2


IONewType ioESTOPS[] =
{
		{	PLC, IN, 0, 0, 1	},
		{	PLC, IN, 0, 1, 1	},
		{	PLC, IN, 0, 2, 1	},
		{	PLC, IN, 0, 3, 1	}
};


IONewType ioProtectField[numLASERs] =
{
		{	SICK0, IN, 0, 0, 1	},
		{	SICK0, IN, 0, 1, 1	},
		{	SICK0, IN, 0, 2, 1	},
		{	SICK1, IN, 0, 0, 1	},
		{	SICK1, IN, 0, 1, 1	},
		{	SICK1, IN, 0, 2, 1	}
};

IONewType ioWarningField[numLASERs] =
{
		{	SICK0, IN, 0, 3, 1	},
		{	SICK0, IN, 0, 4, 1	},
		{	SICK0, IN, 0, 5, 1	},
		{	SICK1, IN, 0, 3, 1	},
		{	SICK1, IN, 0, 4, 1	},
		{	SICK1, IN, 0, 5, 1	}
};

IONewType ioLightsAmber[2];

/* 	DEVICE 	DIR		WORD	BIT		SIZE */
IONewType ioESTOP		= { PLC,	IN, 	0,		0,		1 };
IONewType ioSTART		= { PLC,	IN,		0,		1,		1 };
IONewType ioSTOP		= { PLC,	IN, 	0,		2,		1 };
IONewType ioBUMPER		= { PLC,	IN,		0,		3,		1 };
IONewType ioOPTIC 		= { PLC, 	IN, 	0, 		4, 		1 };

IONewType ioINBYTE1		= { PLC, 	IN, 	1,		0,		8 };
IONewType ioINBYTE2		= { PLC, 	IN,		1,		8,		8 };

IONewType ioCRM 		= { PLC,	OUT, 	0,		0,		1 };
IONewType ioLIGHT		= { PLC,	OUT,	0,		1,		1 };
IONewType ioHORN		= { PLC,	OUT, 	0,		2,		1 };
IONewType ioCHARGING	= { PLC,	OUT,	0,		3,		1 };
IONewType ioTRAVEL 		= { PLC, 	OUT, 	0, 		4, 		1 };

IONewType ioOUTBYTE1	= { PLC, 	OUT, 	1, 		0, 		8 };
IONewType ioOUTBYTE2	= { PLC, 	OUT, 	1, 		8, 		8 };

IONewType ioSICKESTOP		= { SICK0,	IN, 	0,		0,		1 };
IONewType ioSICKSTART		= { SICK0,	IN,		0,		1,		1 };
IONewType ioSICKSTOP		= { SICK0,	IN, 	0,		2,		1 };
IONewType ioSICKBUMPER		= { SICK0,	IN,		0,		3,		1 };
IONewType ioSICKOPTIC 		= { SICK0, 	IN, 	0, 		4, 		1 };

IONewType ioSICKCRM 		= { SICK0,	OUT, 	0,		0,		1 };
IONewType ioSICKLIGHT		= { SICK0,	OUT,	0,		1,		1 };
IONewType ioSICKHORN		= { SICK0,	OUT, 	0,		2,		1 };
IONewType ioSICKCHARGING	= { SICK0,	OUT,	0,		3,		1 };
IONewType ioSICKTRAVEL 		= { SICK0, 	OUT, 	0, 		4, 		1 };





#endif /* DEFSIOTYPE_H */
