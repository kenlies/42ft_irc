#include "RPL_ENDOFMOTD.hpp"

RPL_ENDOFMOTD::RPL_ENDOFMOTD(void) {
	command = "376";
}

RPL_ENDOFMOTD::~RPL_ENDOFMOTD(void) {
}

RPL_ENDOFMOTD &RPL_ENDOFMOTD::operator = (RPL_ENDOFMOTD const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_ENDOFMOTD::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :End of /MOTD command.");
}
