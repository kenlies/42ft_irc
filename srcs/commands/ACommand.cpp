#include "ACommand.hpp"

ACommand::ACommand(void) {
}

ACommand::~ACommand(void) {
}

ACommand &ACommand::operator = (ACommand const &copy) {
	(void)copy;
	return (*this);
}

/* void ACommand::parseMessage(std::string message) {
	//split them based on the spaces
	std::stringstream ss(message);
	std::string word;
	while (ss >> word) {
		this->parameters.push_back(word);
	}
} */

// std::string ACommand::arranger(std::string mes){
// 	return (message);
// }
