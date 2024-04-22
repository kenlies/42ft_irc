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

void PASS::handleCommand(std::string message, Client *source) {
	std::vector<std::string> parameters = parseMessage(message);
	if (parameters.empty())
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command), source);
	else if (source->hasMode('r'))
		return;//FIXME send back ERR_ALREADYREGISTERED
	else if (commands->server->checkPassword(parameters[0])) {
		source->setValidPass();
		source->tryToRegister();
	}
	else
		return;//FIXME send ERR_PASSWDMISMATCH

}

std::string PASS::arranger() {
	return (this->command);
}
