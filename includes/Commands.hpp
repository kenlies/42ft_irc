#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "ACommand.hpp"
#include "Server.hpp"
#include "Channel.hpp"
#include <unordered_map>

class PASS;
class NICK;
class CAP;
class ERR_NEEDMOREPARAMS;

class Commands {
	public:
		Server	*server;

		Commands(Server *s);
		~Commands();

		ACommand	*getCommandFromList(std::string command);
		void		sendCommand(std::string message, Client *target);
		void		sendCommand(std::string message, Channel *target);
		void		sendCommand(std::string message);

		PASS				*pass;
		NICK				*nick;
		CAP					*cap;
		ERR_NEEDMOREPARAMS	*errNeedMoreParams;

	private:
		Commands();
		Commands(Commands &copy);
		Commands &operator = (Commands &copy);

		std::unordered_map<std::string, ACommand*>	commandList;
};

#include "PASS.hpp"
#include "NICK.hpp"
#include "CAP.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

#endif
