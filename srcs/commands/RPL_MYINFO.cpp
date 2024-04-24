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

//FIXME: <available user modes> <available channel modes> [<channel modes with a parameter>]
std::string RPL_MYINFO::arranger(Client *source) {
	return (command + " " + source->getNickname() + " 1.69 ro b");
}