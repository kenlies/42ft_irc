#include "ERR_PASSWDMISMATCH.hpp"

ERR_PASSWDMISMATCH::ERR_PASSWDMISMATCH(void) {
	command = "464";
}

ERR_PASSWDMISMATCH::~ERR_PASSWDMISMATCH(void) {
}

ERR_PASSWDMISMATCH &ERR_PASSWDMISMATCH::operator = (ERR_PASSWDMISMATCH const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_PASSWDMISMATCH::arranger(Client *source) {
	return (command + " " + source->getNickname() + " :Password incorrect");
}
