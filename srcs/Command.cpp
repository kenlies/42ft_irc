#include "Command.hpp"

Command::Command(std::string message, Client *client) {
	this->message = message;
	this->client = client;
}

Command::~Command(void) {
}

// std::vector<std::string> Command::parseMessage(std::string message) {
// //split them based on the spaces
// 	std::stringstream ss(message);
// 	std::vector<std::string> splittedMessage;
// 	std::string word;
// 	while (ss >> word) {
// 		splittedMessage.push_back(word);
// 	}
// 	//display the splitted message
// 	for (size_t i = 0; i < splittedMessage.size(); ++i) {
// 		std::cout << "splittedMessage[" << i << "] = " << splittedMessage[i] << std::endl;
// 	}
// 	return splittedMessage;
// }
