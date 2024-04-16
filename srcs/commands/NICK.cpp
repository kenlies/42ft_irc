#include "NICK.hpp"

NICK::NICK(Server *s) {
	server = s;
	command = "NICK";
}

NICK::~NICK(void) {
}

void NICK::execute(std::string message, Client *client) {
	this->sendMsg(arranger(message), client);
}

std::string NICK::arranger(std::string message) {
	return (this->command + " " + message);
}
