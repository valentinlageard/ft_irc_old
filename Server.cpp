#include "Server.hpp"

Server::Server() {
	_listener_socket.init_listener();
	std::cout << "Listener socket created : " << _listener_socket << std::endl;
}

Server::~Server() {}

void Server::run() {
	// Initializes a client socket
	_client_socket.init_accepted(_listener_socket);
	std::cout << "Client accepted : " << _client_socket << std::endl;
}
