#include "PASS.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

PASS::PASS(Commands *c) {
	commands = c;
	command = "PASS";
}

PASS::~PASS(void) {
}

PASS &PASS::operator = (PASS const &copy) {
	(void)copy;
	return (*this);
}

void PASS::execute(std::string message, Client *source) {
	if (message.empty())
		commands->sendCommand(commands->errNeedmoreparams->arranger(), source);
	else
		commands->sendCommand(arranger(), source);
}

std::string PASS::arranger() {
	return (this->command);
}
