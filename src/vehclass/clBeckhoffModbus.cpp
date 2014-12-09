/*
 * clBeckhoffModbus.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: jbw
 */

#include "clBeckhoffModbus.h"

clBeckhoffModbus::clBeckhoffModbus(
    const char * ip):
    clModbus(ip)
{
    // TODO Auto-generated constructor stub
}

clBeckhoffModbus::~clBeckhoffModbus()
{
    // TODO Auto-generated destructor stub
}


void clBeckhoffModbus::vReadCommand()
{
    int error;
    error = send(socketid, &readcommandmsg, readcommandsize, 0);

    if (error <= 0)
    {
        printf("Error: Read Command\n");
        return -1;
    }
    else
        NextPhase();
}


void clBeckhoffModbus::vReadResponse()
{
    int error;
    char rcvbuffer[512];

    error = recv(socketid, &rcvbuffer, sizeof(rcvbuffer), 0);

    if (error <= 0)
    {
        printf("Error: Read Response\n");
        return -1;
    }
    else
    {
        if (rcvbuffer[7] == 0x03)
        {
            int rcvsize = rcvbuffer[8]/2;
            memcpy((char *) ReadBuffer, &rcvbuffer[9], rcvsize);

        }
        else if (rcvbuffer[7] == 0x83)
            ErrorHandler();

        NextPhase();
    }
}


void clBeckhoffModbus::vWriteCommand()
{
    int error;
    error = send(socketid, &vwritecommand, vwritecommand.size(), 0);

    if (error <= 0)
    {
        printf("Error: Write Command\n");
        return -1;
    }
    else
        NextPhase();

}


void clBeckhoffModbus::vWriteResponse()
{
    int error;
    char rcvbuffer[512];

    error = recv(socketid, &rcvbuffer, sizeof(rcvbuffer), 0);

    if (error <= 0)
    {
        printf("Error: Write Response\n");
        return -1;
    }
    else
    {
        if (rcvbuffer[7] == 0x0F)
        {
            // no data returned in WriteResponse
        }
        else if (rcvbuffer[7] == 0x8F)
            ErrorHandler();

        NextPhase();
    }
}



void clBeckhoffModbus::ErrorHandler()
{


}

