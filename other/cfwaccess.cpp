//:---------------------------------------------------------------------------
//:Description
//
// The CDdPortF wraps access to the CPU32 PortE. It allows setting the direction of
// each data bit which is allocated for I/O. It will not configure or provide
// access to bits allocated for external BUS lines.
//
// This class is not derived from CFwDeviceDriver and only provides basic serivces.
// Most application access to the port should be with access objects.
//
//:---------------------------------------------------------------------------


//:>                 +--------------------------------------+
//:>-----------------|    Static Member Data Definitions    |-----------------
//:>                 +--------------------------------------+

CDdPortF * CDdPortF::s_pThis;			// singleton instance pointer

BYTE CDdPortF::s_Bits;			// singleton instance pointer

BYTE CDdPortF::s_BitConfig;			// I/O bit configuration

//:>                  +-----------------------------------+
//:>------------------|    Member Function Definitions    |-------------------
//:>                  +-----------------------------------+

CDdPortF::CDdPortF(void)
{
	SetInputMask();
}

CDdPortF::~CDdPortF(void)
{
	s_pThis = NULL;
}


// +------------------+
// |  ConfigureBit()  |
// +------------------+

/*
 * Configure a bit for input or output.
 * This method only changes a bit which is assigned as I/O. It ignores the nMode
 * parameter.
 * returns NOERROR if sucessful, else an error code.
 */

EErrorCode CDdPortF::ConfigureBit(
		int nBitNum,						// number of bit in port
		EPortDir eDir,						// input / output direction of bit
		int nMode)							// option bit mode value
{
	UNREFERENCED_PARAMETER(nMode);

	if(IsIOBit(nBitNum) == false)
	{	// not an I/O bit - cannot configure
		ASSERT_INFO(0);	// this is serious
		return(E_INVALIDMODE);
	}

	switch(eDir)
	{
	case edINPUT:
		// clear bit for input
		s_BitConfig &= ~BYTE(BIT(nBitNum));
		break;

	case edOUTPUT:
		// set bit for output
		s_BitConfig |= BYTE(BIT(nBitNum));
		break;

	default:
		return(E_INVALIDMODE);
	}

	SetInputMask();	// need to update
	return(NOERROR);
}


// +--------------------+
// |  ConfigureField()  |
// +--------------------+

/*
 * Configure a bit field for input or output.
 * This method checks that all bits of the field are assigned as I/O. It ignores
 * the nMode parameter.
 *
 * returns NOERROR if successful, else E_INVALIDMODE.
 */

EErrorCode CDdPortF::ConfigureField(
		int nStartBit,						// first bit (LSB) of data field
		int nNumBits,						// number of bits in data field
		EPortDir eDir,						// input / output direction of bit
		int nMode)							// option bit mode value
{
	int nBits;

	// check that all bits in field are assigned to IO
	for(nBits = 0; nBits < nNumBits; ++nBits)
	{
		if(IsIOBit(nStartBit + nBits) == false)
		{
			return(E_INVALIDMODE);
		}
	}

	// now configure all bits in field
	for(nBits = 0; nBits < nNumBits; ++nBits)
	{
		EErrorCode eRC = ConfigureBit(nStartBit + nBits, eDir, nMode);
		if(eRC)
		{	// configure failed
			return(eRC);
		}
	}
	return(NOERROR);
}


// +--------------------+
// |  CreateInputBit()  |
// +--------------------+

/*
 * Configure a bit for input and create an access object
 * This method only changes a bit which is assigned as I/O. It ignores the nMode
 * parameter.
 * returns a CFwAccessObject pointer if successful, else NULL.
 */

CFwAccessObject * CDdPortF::CreateInputBit(
		int nBitNum,						// number of bit in port
		int nMode)							// option bit mode value
{
	EErrorCode eRC = ConfigureBit(nBitNum, edINPUT, nMode);
	CFwAccessObject* pAccess = NULL;

	if(eRC == NOERROR)
	{
		pAccess = new TFwAccessBit<BYTE>(&s_Bits, nBitNum);
	}
	return(pAccess);
}


// +----------------------+
// |  CreateInputField()  |
// +----------------------+

/*
 * Configure a bit field for input and create an access object.
 * This method checks that all bits of the field are assigned as I/O. It ignores
 * the nMode parameter.
 *
 * returns a CFwAccessObject pointer if successful, else NULL.
 */

CFwAccessObject * CDdPortF::CreateInputField(
		int nStartBit,						// first bit (LSB) of data field
		int nNumBits,						// number of bits in data field
		int nMode)							// option bit mode value
{
	EErrorCode eRC = ConfigureField(nStartBit, nNumBits, edINPUT, nMode);
	CFwAccessObject* pAccess = NULL;

	if(eRC == NOERROR)
	{
		pAccess = new TFwAccessField<BYTE>(&s_Bits, nStartBit, nNumBits);
	}
	return(pAccess);
}


// +---------------------+
// |  CreateOutputBit()  |
// +---------------------+

/*
 * Configure a bit for output and create an access object.
 *
 * This method only changes a bit which is assigned as I/O. It ignores the nMode
 * parameter.
 *
 * returns a CFwAccessObject pointer if successful, else NULL.
 */

CFwAccessObject * CDdPortF::CreateOutputBit(
		int nBitNum,						// number of bit in port
		int nMode)							// option bit mode value
{
	EErrorCode eRC = ConfigureBit(nBitNum, edOUTPUT, nMode);
	CFwAccessObject* pAccess = NULL;

	if(eRC == NOERROR)
	{
		pAccess = new TFwAccessBit<BYTE>(&s_Bits, nBitNum);
	}
	return(pAccess);
}


// +-----------------------+
// |  CreateOutputField()  |
// +-----------------------+

// Configure a bit field for output and create an access object.
//
// This method checks that all bits of the field are assigned as I/O. It ignores
// the nMode parameter.
//
// returns a CFwAccessObject pointer if successful, else NULL.
//
CFwAccessObject * CDdPortF::CreateOutputField(
		int nStartBit,						// first bit (LSB) of data field
		int nNumBits,						// number of bits in data field
		int nMode)							// option bit mode value
{
	EErrorCode eRC = ConfigureField(nStartBit, nNumBits, edOUTPUT, nMode);
	CFwAccessObject* pAccess = NULL;

	if(eRC == NOERROR)
	{
		pAccess = new TFwAccessField<BYTE>(&s_Bits, nStartBit, nNumBits);
	}
	return(pAccess);
}

// +-------------+
// |  GetThis()  |
// +-------------+

//:Description
//
// Get the singleton instance of this class.
//
// returns reference to instance.
//
CDdPortF & CDdPortF::GetThis(void)
{
	if(s_pThis == NULL)
	{
		s_pThis = new CDdPortF();
		ASSERT(s_pThis);
	}
	return(*s_pThis);
}


// +--------------+
// |  GetValue()  |
// +--------------+

DWORD CDdPortF::GetValue(void)
{
	return(s_Bits & m_dwInputMask);
}

// +--------------------+
// |  GetValueSigned()  |
// +--------------------+

long CDdPortF::GetValueSigned(void)
{
	return(GetValue());
}


// +----------------+
// |  IsInputBit()  |
// +----------------+

// Check the bit is configured for input.
//
// returns true if input bit, else false if output bit or not configured for I/O
//
bool CDdPortF::IsInputBit(
		int nBitNum)						// number of bit in port
{
	return(IsIOBit(nBitNum) && (s_BitConfig & BIT(nBitNum)) == 0);	// true if clear
}

// +-------------+
// |  IsIOBit()  |
// +-------------+

// Check the bit is configured for input or output.
//
// returns true if I/O bit, else false if not configured for I/O
//
bool CDdPortF::IsIOBit(
		int nBitNum)						// number of bit in port
{
	if(nBitNum < 0 || nBitNum >= 8)
	{	// not a valid bit number
		return(false);
	}

	return(true);  // always allow if valid
}


// +-----------------+
// |  IsOutputBit()  |
// +-----------------+

// Check the bit is configured for output.
//
// returns true if output bit, else false if input bit or not configured for I/O
//
bool CDdPortF::IsOutputBit(
		int nBitNum)						// number of bit in port
{
	return(IsIOBit(nBitNum) && (s_BitConfig & BIT(nBitNum)) != 0);	// true if set
}


// +------------------+
// |  SetInputMask()  |
// +------------------+

// Set the bit mask of input bits.
//
void CDdPortF::SetInputMask(void)
{
	m_dwInputMask = (~s_BitConfig);
}


// +--------------+
// |  SetValue()  |
// +--------------+

void CDdPortF::SetValue(
		DWORD dwData)						// value to write to address
{
	s_Bits = BYTE(dwData);
}


// +--------------+
// |  SetValue()  |
// +--------------+

void CDdPortF::SetValue(
		DWORD dwSetBits,					// bits to set in data
		DWORD dwClrBits)					// bits to clear in data
{
	DWORD dwState = halIrqDisable();
	BYTE cValue = s_Bits;
	cValue &= ~dwClrBits;
	cValue |= dwSetBits;
	s_Bits = cValue;
	halIrqRestore(dwState);
}



