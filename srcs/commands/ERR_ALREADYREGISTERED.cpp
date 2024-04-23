#include "ERR_ALREADYREGISTERED.hpp"

ERR_ALREADYREGISTERED::ERR_ALREADYREGISTERED(void) {
	command = "462";
}

ERR_ALREADYREGISTERED::~ERR_ALREADYREGISTERED(void) {
}

ERR_ALREADYREGISTERED &ERR_ALREADYREGISTERED::operator = (ERR_ALREADYREGISTERED const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_ALREADYREGISTERED::arranger(Client *client) {
	std::string nick = client->getNickname();
	return (command + " " + nick + " :You may not reregister");
}
