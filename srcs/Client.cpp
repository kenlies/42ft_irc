#include "Client.hpp"

Client::Client(int socket_fd) {
	this->socket_fd = socket_fd;
}

Client::~Client() {
}

int Client::getSocketFd(void) const {
	return (this->socket_fd);
}
