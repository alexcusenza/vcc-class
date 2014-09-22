/*
 * clErrorLogging.h
 *
 *  Created on: Aug 26, 2014
 *      Author: jbw
 */

#ifndef CLERRORLOGGING_H_
#define CLERRORLOGGING_H_

#include "MsgTxtDefs.h"

struct MsgListType
{
    int Num;                    // Message number. E.g., 3000.
    char Type;                // Message type. E.g., "F" = "Fatal"
    const char Param;          // Format of message parameters. E.g., "%-4d"
    const char Text;           // Message text. E.g., "Location Code "
};

struct CodeType
{
    int Fatal;
    int Error;
    int Condition;
    int Status;
};

enum errcharval {F, E, C, S};

class clErrorLogging
{
public:
    clErrorLogging();
    virtual ~clErrorLogging();

    void LogMessage();
    void LogTextMessage();

    void Arbitrator(int);   // selects between: fatal, error, condition and status based on error list

                            //  FAULT   STOP    RECOVERABLE
    void Fatal();           // `1       1       0
    void Error();           //  1       1       1
    void Condition();       //  0       1       1
    void Status();          //  0       0       1
    void Reset();


    void CallLog();
    void ErrorQueue();      // buffers error messages

    const CodeType& getCodeVal() const
    {
        return CodeVal;
    }

    void setCodeVal(
        const CodeType& tCodeVal)
    {
        CodeVal = tCodeVal;
    }

private:
    CodeType CodeVal;
    MessType MsgBuff;
    int errcode;

};

#endif /* CLERRORLOGGING_H_ */
