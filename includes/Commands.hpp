#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "ACommand.hpp"
#include "Server.hpp"

#include "ERR_NEEDMOREPARAMS.hpp"

#include <unordered_map>

class PASS;

class Commands {
	public:
		Server	*server;

		Commands(Server *s);
		~Commands();

		ACommand *getCommandFromList(std::string command);

		PASS				*pass;
		ERR_NEEDMOREPARAMS	*errNeedmoreparams;

	private:
		Commands();
		Commands(Commands &copy);
		Commands &operator = (Commands &copy);

		std::unordered_map<std::string, ACommand*>	commandList;
};



/* Commands.pass->arranes

Commands.commandList

new CAP(this); */

#include "PASS.hpp"
#endif
