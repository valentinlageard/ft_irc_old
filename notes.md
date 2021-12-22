# ft_irc

A recreation of an IRC server for 42.

## Architecture

The server has a main socket used by clients to connect to the server. However, the server has to use `accept` to create separate sockets to send and receive from each client. `poll` is used to check if any client's sockets are sending data.

The server also has a list of buffers (one for each client) to store parts of messages. (Actually, these buffers may well be string stream ?) When a message reaches CRLF, the server tries to execute the command.

## Function resume

`int socket(domain, type, protocol)` : creates a socket like a fd.

`int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);` : sets socket options.

`int getsockname(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen);` : gets the address of a socket fd.

`struct protoent *getprotobyname(const char *name);` : gets the protocol's protoent structure given the protocol name.

`struct hostent *gethostbyname(const char *name);` : gets the hostent's host structure given the host name. OBSOLETE ! Should use getaddrinfo instead !

`int getaddrinfo(const char *restrict node, const char *restrict service, const struct addrinfo *restrict hints, struct addrinfo **restrict res);` : returns one (or more) addrinfo structure givent node and service. addrinfo contains internet addresses usable to bind or connect. `freeaddrinfo` releases the res linked list

`int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);` : assigns the addr address to the sockfd.

`int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);` : connects the sockfd to the addr.

`int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen);` : creates a new socketfd.