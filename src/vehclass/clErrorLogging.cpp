/*
 * clErrorLogging.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: jbw
 */

#include "clErrorLogging.h"

clErrorLogging::clErrorLogging()
{

}

clErrorLogging::~clErrorLogging()
{

}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */

void clErrorLogging::Arbitrator(int errcode)
{
    MsgBuff.ErrorValue = errcode;

    switch (errcharval)
    {
        case E:
        {
            Error();
            break;
        }

        case F:
        {
            Fatal();
            break;
        }

        case C:
        {
            Condition();
            break;
        }

        case S:
        {
            Status();
            break;
        }

    }

}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
void clErrorLogging::Fatal()
{

    if (CodeVal.Fatal == 0)
    {
        CodeVal.Fatal = errcode;
        MsgBuff.ErrorValue = errcode;
        CallLog();
    }
    return;

}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
void clErrorLogging::Error()
{
    if (CodeVal.Condition == 0 ||
            CodeVal.Condition >= MG_OverWrite_Conds_VehMgr_Start)
    {
        CodeVal.Error = errcode;
        MsgBuff.ErrorValue = errcode;
        CallLog();
    }

    return;
}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
void clErrorLogging::Condition()
{
    if (CodeVal.Condition == 0 ||
            (CodeVal.Condition >= MG_OverWrite_Conds_VehMgr_Start &&
                    CodeVal.Condition > errcode))
    {
        CodeVal.Condition = errcode;
        MsgBuff.ErrorValue = errcode;
        CallLog();
    }
    return;
}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */
void clErrorLogging::Status()
{
    CodeVal.Status = errcode;
    MsgBuff.ErrorValue = errcode;
    CallLog();
    return;
}

/* +----------------------------------------------------+
 * Member Function
 * +----------------------------------------------------+
 */

void clErrorLogging::CallLog()
{
    LogMessage(&Buffer);
    return;

}
