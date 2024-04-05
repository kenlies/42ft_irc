#include "ACommand.hpp"

ACommand::ACommand(std::string message, Client *client) {
	this->client = client;
	std::vector<std::string> splittedMessage = parseMessage(message);
	if (splittedMessage.size() == 0)
		return ;
	this->command = splittedMessage[0];
	for (size_t i = 1; i < splittedMessage.size(); i++) {
		this->parameters.push_back(splittedMessage[i]);
	}


	//display the command and the parameters//DELETE THIS
	std::cout << "Command: " << this->command << std::endl;
	std::cout << "Parameters: ";
	for (size_t i = 0; i < this->parameters.size(); i++) {
		std::cout << this->parameters[i] << " ";
	}
	std::cout << std::endl;
}

ACommand::~ACommand(void) {
}

std::vector<std::string> ACommand::parseMessage(std::string message) {
//split them based on the spaces
	std::stringstream ss(message);
	std::vector<std::string> splittedMessage;
	std::string word;
	while (ss >> word) {
		splittedMessage.push_back(word);
	}
	return splittedMessage;
}

std::string ACommand::getCommand(void) const {
	return this->command;
}
