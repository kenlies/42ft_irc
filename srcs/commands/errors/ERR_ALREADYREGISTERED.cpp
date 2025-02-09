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

std::string const ERR_ALREADYREGISTERED::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :You may not reregister");
}
