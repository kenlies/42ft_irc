#include "Client.hpp"

Client::Client(int socketFd) {
	this->socketFd = socketFd;
}

Client::~Client() {
}

int Client::getSocketFd(void) const {
	return (this->socketFd);
}
