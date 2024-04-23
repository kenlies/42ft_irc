#include "ERR_NONICKNAMEGIVEN.hpp"

ERR_NONICKNAMEGIVEN::ERR_NONICKNAMEGIVEN(void) {
	command = "431";
}

ERR_NONICKNAMEGIVEN::~ERR_NONICKNAMEGIVEN(void) {
}

ERR_NONICKNAMEGIVEN &ERR_NONICKNAMEGIVEN::operator = (ERR_NONICKNAMEGIVEN const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NONICKNAMEGIVEN::arranger(Client *client) {
	std::string nick = client->getNickname();
	return (command + " " + nick + " :No nickname given");
}
