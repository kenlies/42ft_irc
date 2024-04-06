#include "ACommand.hpp"

ACommand::ACommand(void) {
}

ACommand::~ACommand(void) {
}

void ACommand::parseMessage(std::string message) {
	//save the message
	this->message = message;
	//split them based on the spaces
	std::stringstream ss(message);
	std::string word;
	while (ss >> word) {
		this->parameters.push_back(word);
	}
	//split the command from the parameters
	if (this->parameters.size() > 0) {
		this->command = this->parameters[0];
		this->parameters.erase(this->parameters.begin());
	}
}

std::string ACommand::getCommand(void) const {
	return this->command;
}
