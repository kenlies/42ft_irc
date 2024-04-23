#include "ERR_NICKNAMEINUSE.hpp"

ERR_NICKNAMEINUSE::ERR_NICKNAMEINUSE(void) {
	command = "433";
}

ERR_NICKNAMEINUSE::~ERR_NICKNAMEINUSE(void) {
}

ERR_NICKNAMEINUSE &ERR_NICKNAMEINUSE::operator = (ERR_NICKNAMEINUSE const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NICKNAMEINUSE::arranger(std::string sourceNickname, Client *client) {
	std::string nick = client->getNickname();
	return (command + " " + nick + " " + sourceNickname + " :Not enough parameters");
}
