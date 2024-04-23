#include "ERR_ERRONEUSNICKNAME.hpp"

ERR_ERRONEUSNICKNAME::ERR_ERRONEUSNICKNAME(void) {
	command = "432";
}

ERR_ERRONEUSNICKNAME::~ERR_ERRONEUSNICKNAME(void) {
}

ERR_ERRONEUSNICKNAME &ERR_ERRONEUSNICKNAME::operator = (ERR_ERRONEUSNICKNAME const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_ERRONEUSNICKNAME::arranger(std::string sourceNickname, Client *source) {
	return (command + " " + source->getNickname() + " " + sourceNickname + " :Erroneus nickname");
}
