#include "RPL_MOTDSTART.hpp"

RPL_MOTDSTART::RPL_MOTDSTART(void) {
	command = "375";
}

RPL_MOTDSTART::~RPL_MOTDSTART(void) {
}

RPL_MOTDSTART &RPL_MOTDSTART::operator = (RPL_MOTDSTART const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_MOTDSTART::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :- Message of the day -");
}
