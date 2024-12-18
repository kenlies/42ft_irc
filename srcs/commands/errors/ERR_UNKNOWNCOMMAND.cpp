#include "ERR_UNKNOWNCOMMAND.hpp"

ERR_UNKNOWNCOMMAND::ERR_UNKNOWNCOMMAND(void) {
	command = "421";
}

ERR_UNKNOWNCOMMAND::~ERR_UNKNOWNCOMMAND(void) {
}

ERR_UNKNOWNCOMMAND &ERR_UNKNOWNCOMMAND::operator = (ERR_UNKNOWNCOMMAND const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_UNKNOWNCOMMAND::arranger(std::string const sourceCommand, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + sourceCommand + " :Unknown command");
}
