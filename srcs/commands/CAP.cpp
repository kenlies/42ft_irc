#include "CAP.hpp"

CAP::CAP(Server *s) {
	server = s;
	command = "CAP";
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message, Client *client) {
	this->sendMsg(arranger(message), client);
}

std::string CAP::arranger(std::string message) {
	return (this->command + " " + message);
}
