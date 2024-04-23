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

std::string ERR_PASSWDMISMATCH::arranger(Client *client) {
	std::string nick = client->getNickname();
	return (command + " " + nick + " :Password incorrect");
}
