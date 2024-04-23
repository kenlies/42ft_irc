#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include "ACommand.hpp"
# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include <unordered_map>

class PASS;
class NICK;
class USER;
class ERR_NEEDMOREPARAMS;
class ERR_ALREADYREGISTERED;
class ERR_PASSWDMISMATCH;

class Commands {
	public:
		Server	*server;

		Commands(Server *s);
		~Commands();

		ACommand	*getCommandFromList(std::string command);
		void		sendCommand(std::string message, Client *target);
		void		sendCommand(std::string message, Channel *target);
		void		sendCommand(std::string message);

		PASS					*pass;
		NICK					*nick;
		USER					*user;
		ERR_NEEDMOREPARAMS		*errNeedMoreParams;
		ERR_ALREADYREGISTERED	*errAlreadyRegistered;
		ERR_PASSWDMISMATCH		*errPasswMismatch;

	private:
		Commands();
		Commands(Commands &copy);
		Commands &operator = (Commands &copy);

		std::unordered_map<std::string, ACommand*>	commandList;
};

# include "PASS.hpp"
# include "NICK.hpp"
# include "USER.hpp"
# include "ERR_NEEDMOREPARAMS.hpp"
# include "ERR_ALREADYREGISTERED.hpp"
# include "ERR_PASSWDMISMATCH.hpp"

#endif
