#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	pass = new PASS(this);
	errNeedmoreparams = new ERR_NEEDMOREPARAMS();

	commandList["PASS"] = this->pass;
	commandList["ERR_NEEDMOREPARAMS"] = this->errNeedmoreparams;
}

Commands::~Commands() {
	delete pass;
	delete errNeedmoreparams;
}

ACommand *Commands::getCommandFromList(std::string command) {
	return (commandList[command]);
}
