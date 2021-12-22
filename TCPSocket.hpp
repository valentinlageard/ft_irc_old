#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include <cerrno>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
// Needed to close a fd (however, it's a c header...)
#include <unistd.h>

class TCPSocket {
public:
	TCPSocket();
	virtual ~TCPSocket();

	void init_listener();
	void init_accepted(const TCPSocket & listener_socket);

	int get_socketfd() const;
	struct sockaddr_in get_address() const;

private:
	TCPSocket(const TCPSocket & original);
	int _socketfd;
	struct sockaddr_in _address; // sockaddr_in is used for IP communication
};

std::ostream& operator<< (std::ostream& stream, const TCPSocket & tcpsocket);

#endif
