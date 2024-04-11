#include "Client.hpp"

Client::Client(int socketFd) {
	this->socketFd = socketFd;
}

Client::~Client() {
}

void Client::addBufferToMsgBuffer(std::string buffer) {
	// FIXME: Maybe better handling for overflow???
	// if the message becomes longer than MSG_BUFFER_SIZE
	if (this->msgBuffer.length() + buffer.length() > MSG_BUFFER_SIZE) {
		// only accepts the message for the defined MSG_BUFFER_SIZE
		this->msgBuffer += buffer.substr(0, MSG_BUFFER_SIZE - this->msgBuffer.length());
		//finds the last occurance of the \r\n, if that exists
		size_t found = this->msgBuffer.rfind("\r\n");
		// if \r\n exists it removes the rest of the message
		if (found != std::string::npos)
			this->msgBuffer = this->msgBuffer.substr(0, found);
		// if it is longer than MSG_BUFFER_SIZE and no \r\n it clears the messageBuffer!
		else
			this->msgBuffer.clear();
		std::cout << RED << "Error: Message buffer is full!" << std::endl;
	}
	else
		this->msgBuffer += buffer;
}

bool Client::msgCompleted(void) {
	if (this->msgBuffer.find("\r\n") != std::string::npos) {
		return (true);
	}
	return (false);
}

//Getters

int Client::getSocketFd(void) {
	return (this->socketFd);
}

std::string Client::getMsgFromBuffer(void) {
	std::string message = this->msgBuffer.substr(0, this->msgBuffer.find("\r\n"));
	this->msgBuffer = this->msgBuffer.substr(this->msgBuffer.find("\r\n") + 2);
	return (message);
}
