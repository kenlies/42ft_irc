#include "ERR_NEEDMOREPARAMS.hpp"

ERR_NEEDMOREPARAMS::ERR_NEEDMOREPARAMS(void) {
	command = "ERR_NEEDMOREPARAMS";
}

ERR_NEEDMOREPARAMS::~ERR_NEEDMOREPARAMS(void) {
}

ERR_NEEDMOREPARAMS &ERR_NEEDMOREPARAMS::operator = (ERR_NEEDMOREPARAMS const &copy) {
	(void)copy;
	return (*this);
}

void ERR_NEEDMOREPARAMS::execute(std::string message, Client *source) {
	(void)message;
	(void)source;
}

std::string ERR_NEEDMOREPARAMS::arranger() {
	return (command + " :Not enough parameters");
}
