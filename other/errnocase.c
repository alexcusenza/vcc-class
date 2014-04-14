switch(errno)
{
case EACCES:
{
	sprintf((char*)MBuffer.MsgText, "Write permission is denied %d\n", errno);
	break;
}
case EAFNOSUPPORT:
{
	sprintf((char*)MBuffer.MsgText, "Implementation does not support address family %d\n", errno);
	break;
}
case EINVAL:
{
	sprintf((char*)MBuffer.MsgText, "Unknown protocol or invalid flags in type %d\n", errno);
	break;
}
case EMFILE:
{
	sprintf((char*)MBuffer.MsgText, "Process file table over-flow %d\n", errno);
	break;
}
case ENFILE:
{
	sprintf((char*)MBuffer.MsgText, "System limit on open files reached %d\n", errno);
	break;
}
case ENOBUFS:
{
	sprintf((char*)MBuffer.MsgText, "Insufficient memory is available %d\n", errno);
	break;
}
case ENOMEM:
{
	sprintf((char*)MBuffer.MsgText, "Insufficient memory is available %d\n", errno);
	break;
}

case EPROTONOSUPPORT:
{
	sprintf((char*)MBuffer.MsgText, "Protocol type or specified protocol is not supported %d\n", errno);
	break;
}
case EPERM:
{
	sprintf((char*)MBuffer.MsgText, "Tried to connect to broadcast without broadcast flag enabled %d\n", errno);
	break;
}

case EADDRINUSE:
{
	sprintf((char*)MBuffer.MsgText, "Local address already in use %d\n", errno);
	break;
}
case EAFNOSUPPORT:
{
	sprintf((char*)MBuffer.MsgText, "Passed address not in correct address family %d\n", errno);
	break;
}

case EAGAIN:
{
	sprintf((char*)MBuffer.MsgText, "No free ports or insufficient entries in routing cache %d\n", errno);
	break;
}
case EALREADY:
{
	break;
}
case EBADF:
{
	sprintf((char*)MBuffer.MsgText, "The file descriptor is not valid in descriptor table %d\n", errno);
	break;
}
case ECONNREFUSED:
{
	sprintf((char*)MBuffer.MsgText, "No-One listening on the remote address %d\n", errno);
	break;
}
case EFAULT:
{
	sprintf((char*)MBuffer.MsgText, "The socket structure address is outside the user's address space %d\n", errno);
	break;
}
case EINPROGRESS:
{
	break;
}
case EINTR:
{
	sprintf((char*)MBuffer.MsgText, "The system call was interrupted by a signal that was caught %d\n", errno);
	break;
}
case EISCONN:
{
	sprintf((char*)MBuffer.MsgText, "Connection Opened to Beckhoff Unit %d\n", errno);
	break;
}
case ENETUNREACH:
{
	sprintf((char*)MBuffer.MsgText, "The network is unreachable %d\n", errno);
	break;
}
case ENOTSOCK:
{
	sprintf((char*)MBuffer.MsgText, "The file descriptor is not associated with a socket %d\n", errno);
	break;
}
case ETIMEDOUT:
{
	sprintf((char*)MBuffer.MsgText, "A timeout has occurred while attempting connection %d\n", errno);
	break;
}



