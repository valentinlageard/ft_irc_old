#include "TCPSocket.hpp"

TCPSocket::TCPSocket() {
	// Creates the TCP socket
	// AF_INET specifies use of IPV4 (what about IPV6 ? AF_INET6)
	// SOCK_STREAM is TCP
	// protocol arg is set to 0 when using TCP/IP
	// Source : man tcp, man socket
	if ((_socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		throw std::runtime_error(strerror(errno));
	}
}

TCPSocket::~TCPSocket() {
	close(_socketfd);
}

void TCPSocket::init_listener() {
	// Initializes a listening socket used by the server to accept new clients

	// Sets up the address structure for server's listening socket (used by clients to connect)
	_address.sin_family = AF_INET;
	_address.sin_port = htons(6667); // Sets up port (should use a specified port instead)
	_address.sin_addr.s_addr = INADDR_ANY; // Sets up address (should use a specified address instead)

	// Binds an address (IP + PORT essentially) to our _socketfd
	if (bind(_socketfd, (struct sockaddr *)&_address, sizeof(_address)) < 0) {
		throw std::runtime_error(strerror(errno));
	}

	// Specifies the socket as passive : will be used to accept client's connections
	// The second argument (backlog) specifies the max number of client's trying to connect (at the same time)
	if (listen(_socketfd, 1) < 0) {
		throw std::runtime_error(strerror(errno));
	}
}

void TCPSocket::init_accepted(const TCPSocket & listener_socket) {
	// Initializes a new TCPSocket accepted by listener socket

	socklen_t remote_address_len;

	// Accepts a new connection from listener socket and fills the new socket
	if ((_socketfd = accept(listener_socket.get_socketfd(), (struct sockaddr *)&_address, &remote_address_len)) < 0) {
		throw std::runtime_error(strerror(errno));
	}
}
int TCPSocket::get_socketfd() const {
	return _socketfd;
}

struct sockaddr_in TCPSocket::get_address() const {
	return _address;
}

std::ostream& operator<< (std::ostream& stream, const TCPSocket & tcpsocket) {
	stream << tcpsocket.get_socketfd();
	return stream;
}
