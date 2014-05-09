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

enum eIOdefs
{
	eioESTOP,
	eioSTART,
	eioCRM,
	eioBUMPER
};

IODefType ioESTOPS[] =
{
		{ PLC, IN, tBool, 0, 0, 1 },
		{ PLC, IN, tBool, 0, 1, 1 },
		{ PLC, IN, tBool, 0, 2, 1 },
		{ PLC, IN, tBool, 0, 3, 1 }
};


IODefType ioProtectField[numLASERs] =
{
		{ SICK0, IN, tBool, 0, 0, 1	},
		{ SICK0, IN, tBool, 0, 1, 1	},
		{ SICK0, IN, tBool, 0, 2, 1	},
		{ SICK1, IN, tBool, 0, 0, 1	},
		{ SICK1, IN, tBool, 0, 1, 1	},
		{ SICK1, IN, tBool, 0, 2, 1	}
};

IODefType ioWarningField[numLASERs] =
{
		{ SICK0, IN, tBool, 0, 3, 1	},
		{ SICK0, IN, tBool, 0, 4, 1	},
		{ SICK0, IN, tBool, 0, 5, 1	},
		{ SICK1, IN, tBool, 0, 3, 1	},
		{ SICK1, IN, tBool, 0, 4, 1	},
		{ SICK1, IN, tBool, 0, 5, 1	}
};

IODefType ioLightsAmber[2];

						/* 	DEV 	DIR		DATA	WORD	BIT		SIZE */
IODefType ioESTOP		= { PLC,	IN, 	tBool, 	0,		0,		1 };
IODefType ioSTART		= { PLC,	IN,		tBool, 	0,		1,		1 };
IODefType ioSTOP		= { PLC,	IN, 	tBool, 	0,		2,		1 };
IODefType ioBUMPER		= { PLC,	IN,		tBool, 	0,		3,		1 };
IODefType ioOPTIC 		= { PLC, 	IN, 	tBool, 	0, 		4, 		1 };

IODefType ioINBYTE1		= { PLC, 	IN, 	tByte,	1,		0,		8 };
IODefType ioINBYTE2		= { PLC, 	IN,		tByte,	1,		8,		8 };

IODefType ioCRM 		= { PLC,	OUT, 	tBool, 	0,		0,		1 };
IODefType ioLIGHT		= { PLC,	OUT,	tBool, 	0,		1,		1 };
IODefType ioHORN		= { PLC,	OUT, 	tBool, 	0,		2,		1 };
IODefType ioCHARGING	= { PLC,	OUT,	tBool, 	0,		3,		1 };
IODefType ioTRAVEL 		= { PLC, 	OUT, 	tBool, 	0, 		4, 		1 };

IODefType ioOUTBYTE1	= { PLC, 	OUT, 	tByte,	1, 		0, 		8 };
IODefType ioOUTBYTE2	= { PLC, 	OUT, 	tByte,	1, 		8, 		8 };

IODefType ioSICKESTOP		= { SICK0,	IN, 	tBool, 	0,		0,		1 };
IODefType ioSICKSTART		= { SICK0,	IN,		tBool, 	0,		1,		1 };
IODefType ioSICKSTOP		= { SICK0,	IN, 	tBool, 	0,		2,		1 };
IODefType ioSICKBUMPER		= { SICK0,	IN,		tBool, 	0,		3,		1 };
IODefType ioSICKOPTIC 		= { SICK0, 	IN, 	tBool, 	0, 		4, 		1 };

IODefType ioSICKCRM 		= { SICK0,	OUT, 	tBool, 	0,		0,		1 };
IODefType ioSICKLIGHT		= { SICK0,	OUT,	tBool, 	0,		1,		1 };
IODefType ioSICKHORN		= { SICK0,	OUT, 	tBool, 	0,		2,		1 };
IODefType ioSICKCHARGING	= { SICK0,	OUT,	tBool, 	0,		3,		1 };
IODefType ioSICKTRAVEL 		= { SICK0, 	OUT, 	tBool, 	0, 		4, 		1 };





#endif /* DEFSIOTYPE_H */
