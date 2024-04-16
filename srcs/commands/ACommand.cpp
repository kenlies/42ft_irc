#include "ACommand.hpp"

ACommand::ACommand(void) {
}

ACommand::~ACommand(void) {
}

/* void ACommand::parseMessage(std::string message) {
	//split them based on the spaces
	std::stringstream ss(message);
	std::string word;
	while (ss >> word) {
		this->parameters.push_back(word);
	}
} */

void ACommand::sendMsg(std::string message, Client *target) {
	std::string response = BLUE "Received this: " RESET;
    response += message;
	response += "\n";

    send(target->getSocketFd(), response.c_str(), response.length(), 0);
}

// std::string ACommand::arranger(std::string message){
// 	return (message);
// }
