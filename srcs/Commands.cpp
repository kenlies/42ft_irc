#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	pass = new PASS(this);
	nick = new NICK(this);
	cap = new CAP(this);
	errNeedMoreParams = new ERR_NEEDMOREPARAMS();

	commandList["PASS"] = this->pass;
	commandList["ERR_NEEDMOREPARAMS"] = this->errNeedMoreParams;
}

Commands::~Commands() {
	delete pass;
	delete errNeedMoreParams;
}

ACommand *Commands::getCommandFromList(std::string command) {
	return (commandList[command]);
}

void Commands::sendCommand(std::string message, Client *target) {
	std::string response = BLUE "Received this: " RESET;
    response += message;
	response += "\n";

    send(target->getSocketFd(), response.c_str(), response.length(), 0);
}

void Commands::sendCommand(std::string message, Channel *target) {
	// send command to every client in channel
	(void)message;
	(void)target;
	return ;
}

void Commands::sendCommand(std::string message) {
	// send command to every client in server
	(void)message;
	return ;
}
