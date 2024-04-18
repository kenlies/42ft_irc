#include "PASS.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

PASS::PASS(Server *s) {
	server = s;
	command = "PASS";
	server->addCommandToList(command, this);
}

PASS::~PASS(void) {
}

void PASS::execute(std::string message, Client *client) {
	if (message.empty())
		sendMsg(server->getCommandFromList("ERR_NEEDMOREPARAMS")->arranger(), client);
	else
		this->sendMsg(arranger(), client);
}

std::string PASS::arranger() {
	return (this->command);
}
