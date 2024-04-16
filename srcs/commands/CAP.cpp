#include "CAP.hpp"

CAP::CAP(Server *s) {
	server = s;
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message, Client *client) {
	// std::cout << "CAP command: Message: " << message << std::endl;
	this->sendMsg(message, client);

}

std::string CAP::arranger(std::string message) {
	return ("CAP " + message);
}
