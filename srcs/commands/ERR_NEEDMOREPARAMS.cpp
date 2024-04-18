#include "ERR_NEEDMOREPARAMS.hpp"

ERR_NEEDMOREPARAMS::ERR_NEEDMOREPARAMS(Server *s) {
	server = s;
	command = "ERR_NEEDMOREPARAMS";
	server->addCommandToList(command, this);
}

ERR_NEEDMOREPARAMS::~ERR_NEEDMOREPARAMS(void) {
}

void ERR_NEEDMOREPARAMS::execute(std::string message, Client *client) {
	(void)message;
	(void)client;
}

std::string ERR_NEEDMOREPARAMS::arranger() {
	return (command + " :Not enough parameters");
}
