/*
 * clBeckhoffModbus.h
 *
 *  Created on: Oct 5, 2014
 *      Author: jbw
 */

#ifndef CLBECKHOFFMODBUS_H_
#define CLBECKHOFFMODBUS_H_

#include <errno.h>

#include "clModbus.h"

const char * chPLCIP = "172.16.17.75";

class clBeckhoffModbus : public clModbus
{
public:
    clBeckhoffModbus( const char *);
    virtual ~clBeckhoffModbus();

    void vReadCommand();
    void vReadResponse();
    void vWriteCommand();
    void vWriteResponse();
    void ErrorHandler();

private:
    unsigned ReadBuffer;

};

#endif /* CLBECKHOFFMODBUS_H_ */
