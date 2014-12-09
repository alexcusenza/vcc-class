/*
 * clModbus.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: jbw
 */

#include "clModbus.h"

clModbus::clModbus(const char * ip)
:CDdLinuxThread(SCHED_FIFO, 1),
 socketid(0),
 ipaddress(ip)
{
    // TODO Auto-generated constructor stub
}

clModbus::~clModbus()
{
    // TODO Auto-generated destructor stub
}

EErrorCode clModbus::Startup(void)
{
    eRR = ConnectProcess();
    if (eRR == NOERROR)
    {
        eRR = StartThread();
    }

    return eRR;
}


void clModbus::ConnectProcess()
{
    while (true)
    {
        switch(connectstate)
        {
            case 0:
            {
                OpenSocket();

                break;
            }

            case 1:
            {
                eRR = ConnectSocket();

                if (eRR)
                {
                    //start timer
                    connectstate = 2;
                }
                else
                    connectstate = 4;

                break;
            }

            case 2:
            {
                if (timerexpire)
                    connectstate = 3;

                break;
            }

            case 3:
            {
                if (attempts > MAXATTEMPTS)
                {
                    attempts = 0;
                    connectstate = 0;
                }
                else
                {
                    attempts++;
                    connectstate = 1;
                }

                break;
            }

            case 4:
            {
                //set status bytes
                //set command function // read or write
                connectstate = 0;
                break;
            }
        }
    }
}

EErrorCode clModbus::OpenSocket()
{
    EErrorCode eRR = NOERROR;

    if (socketid != 0)
    {
        close(socketid);
        socketid = 0;
    }

    socketid = socket(AF_INET, SOCK_STREAM, 0);

    if (socketid < 0)
    {
        eRR = E_NOTCONNECTED;
    }
    else
    {
        memset(&socketname, 0, sizeof(socketname));
        socketname.sin_family = AF_INET;
        socketname.sin_port = htons(PORT);
        socketname.sin_addr.s_addr = inet_addr(ipaddress);

        // Set the socket in non-blocking mode
        fcntl(socketid, FNONBLOCK, FNDELAY);
    }
    return eRR;
}

EErrorCode clModbus::ConnectSocket()
{
    EErrorCode eRR = NOERROR;

    eRR = connect(socketid, (struct sockaddr *)&socketname, sizeof(struct sockaddr_in));

    if (eRR < 0)
    {
        printf("socket connect error - errno: %d\n", errno);
        eRR = E_NOTCONNECTED;
    }
    else
        printf("socket connected\n");

    return eRR;
}

void clModbus::setReadCommandHeader(char *data, int size)
{
    readcommandmsg = (char *) &data;
    readcommandsize = size;
}

void clModbus::setWriteCommandHeader(char *data, int size)
{
    std::vector<char> vwriteheader(&data, size);
}


void clModbus::setWriteCommandData(char *data, int size)
{
    std::vector<char> vdata(&data, size);

    vwritecommand.insert(vwritecommand.end(), vwriteheader.begin(), vwriteheader.end());
    vwritecommand.insert(vwritecommand.end(), vdata.begin(), vdata.end());
}

void clModbus::NextPhase()
{
    Command = (eCmdType)(Command++);
}

void clModbus::Read()
{
    int error;
    error = send(socketid, &readcommandmsg, readcommandsize, 0);
}

void clModbus::RunThread(void)
{
    while(true)
    {
        switch(Command)
        {
            case readcmd:
            {
                vReadCommand();
                break;
            }
            case readresp:
            {
                vReadResponse();
                break;
            }
            case writecmd:
            {
                vWriteCommand();
                break;
            }
            case writeresp:
            {
                vWriteResponse();
                break;
            }
        }
    }
}



