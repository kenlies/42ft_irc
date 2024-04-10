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
		throw std::runtime_error("Error: Message buffer is full!");
	}
	this->msgBuffer += buffer;
}

bool Client::validMessage(void) {
	// if there is a \r\n in the msgBuffer, then the message is valid!
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