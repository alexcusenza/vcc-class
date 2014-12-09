/*
 * clModbus.h
 *
 *  Created on: Oct 5, 2014
 *      Author: jbw
 */

#ifndef CLMODBUS_H_
#define CLMODBUS_H_
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <vector>

#include "CDdLinuxThread.h"

#define PORT 502

enum eCmdType
{
    readcmd,
    readresp,
    writecmd,
    writeresp
} Command;

const int MAXATTEMPTS = 10;

class clModbus : CDdLinuxThread
{
public:
    clModbus(const char *);
    virtual ~clModbus();

    EErrorCode Startup();
    void Shutdown();
    void RunThread();
    void ConnectProcess();

    void setReadCommandHeader(char *, int);
    void setWriteCommandHeader(char *, int);
    void setWriteCommandData(char *, int);

protected:
    void NextPhase();
    EErrorCode OpenSocket() = 0;
    EErrorCode ConnectSocket() = 0;
    virtual void vCloseSocket();
    virtual void vReadCommand() = 0;
    virtual void vReadResponse() = 0;
    virtual void vWriteCommand() = 0;
    virtual void vWriteResponse() = 0;

    static sockaddr_in socketname;
    int socketid;

    char * readcommandmsg;
    int readcommandsize;

    std::vector<char> vwriteheader;
    std::vector<char> vwritecommand;

private:
    const char * ipaddress;
    int connectstate;
    int timerexpire;
    int attempts;
    EErrorCode eRR;
};

#endif /* CLMODBUS_H_ */
