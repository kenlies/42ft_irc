#include "RPL_MYINFO.hpp"

RPL_MYINFO::RPL_MYINFO(void) {
	command = "004";
}

RPL_MYINFO::~RPL_MYINFO(void) {
}

RPL_MYINFO &RPL_MYINFO::operator = (RPL_MYINFO const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_MYINFO::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " 3.69 or klit kl");
}
