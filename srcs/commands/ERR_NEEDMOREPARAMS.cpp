#include "ERR_NEEDMOREPARAMS.hpp"

ERR_NEEDMOREPARAMS::ERR_NEEDMOREPARAMS(void) {
//	server = s;
	command = "ERR_NEEDMOREPARAMS";
//	server->addCommandToList(command, this);
}

ERR_NEEDMOREPARAMS::~ERR_NEEDMOREPARAMS(void) {
}

ERR_NEEDMOREPARAMS &ERR_NEEDMOREPARAMS::operator = (ERR_NEEDMOREPARAMS const &copy) {
	(void)copy;
	return (*this);
}

void ERR_NEEDMOREPARAMS::execute(std::string message, Client *client) {
	(void)message;
	(void)client;
}

std::string ERR_NEEDMOREPARAMS::arranger() {
	return (command + " :Not enough parameters");
}
