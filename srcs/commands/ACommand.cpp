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

void ACommand::handleCommand(std::string message, Client *source) {
	(void)message;
	(void)source;
}
