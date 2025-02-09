#include "RPL_NOTOPIC.hpp"

RPL_NOTOPIC::RPL_NOTOPIC(void) {
	command = "331";
}

RPL_NOTOPIC::~RPL_NOTOPIC(void) {
}

RPL_NOTOPIC &RPL_NOTOPIC::operator = (RPL_NOTOPIC const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_NOTOPIC::arranger(Client *source, Channel *channel) const {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :No topic is set");
}
