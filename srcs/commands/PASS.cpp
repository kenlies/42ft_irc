#include "PASS.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

PASS::PASS(Commands *c) {
//	server = s;
	commands = c;
	command = "PASS";
//	server->addCommandToList(command, this);
}

PASS::~PASS(void) {
}

PASS &PASS::operator = (PASS const &copy) {
	(void)copy;
	return (*this);
}

void PASS::execute(std::string message, Client *client) {
	if (message.empty())
		sendMsg(commands->getCommandFromList("ERR_NEEDMOREPARAMS")->arranger(), client);
	else
		this->sendMsg(arranger(), client);
}

std::string PASS::arranger() {
	return (this->command);
}
