#ifndef SERVER_HPP
#define SERVER_HPP

#include "TCPSocket.hpp"

class Server {

public:
	Server();
	virtual ~Server();

	void run();

private:
	Server(const Server & original); // Copy constructor is private because we don't need to copy it
	TCPSocket _listener_socket;
	TCPSocket _client_socket;
};

#endif
