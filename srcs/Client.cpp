#include "Client.hpp"

Client::Client(int socketFd) {
	this->socketFd = socketFd;
}

Client::~Client() {
}

int Client::getSocketFd(void) {
	return (this->socketFd);
}

void Client::addBufferToMsgBuffer(std::string buffer) {
	if (this->msgBuffer.length() + buffer.length() > 512) {
		this->msgBuffer += buffer.substr(0, 512 - this->msgBuffer.length());
		size_t found = this->msgBuffer.rfind("\r\n");
		if (found != std::string::npos)
			this->msgBuffer = this->msgBuffer.substr(0, found);
		else
			this->msgBuffer.clear();
		std::cout << RED << "Error: Message buffer is full!" << std::endl;
	}
	else
		this->msgBuffer += buffer;
}

bool Client::validMessage(void) {
	if (this->msgBuffer.find("\r\n") != std::string::npos) {
		return (true);
	}
	return (false);
}

std::string Client::getMsgBuffer(void) {
	std::string message = this->msgBuffer.substr(0, this->msgBuffer.find("\r\n") + 2);
	this->msgBuffer = this->msgBuffer.substr(this->msgBuffer.find("\r\n") + 2);
	return (message);
}
