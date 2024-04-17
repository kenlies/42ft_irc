#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
#include "Server.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <sys/socket.h>

//class Server;

class ACommand {

	public:

		// Constructors and destructors
		ACommand(void);
		ACommand &operator=(ACommand const &copy);
		virtual ~ACommand(void);

		// Methods
		virtual void	execute(std::string message, Client *client) = 0;
	//	void			parseMessage(std::string message);
		void			sendMsg(std::string message, Client *target);
		// void			sendMsg(std::string message, Channel *target);
		// void			sendMsg(std::string message);

	protected:

		// Canonical form
		ACommand(ACommand const &copy);

		// Attributes
		Server						*server;
		std::string					command;
//		std::vector<std::string>	parameters;

		// Methods

		// generic arrangers that could have string or vector of strings as parameter to send as command parameters
		// We would use them something like this: sendMsg(arranger(source, target_client, "string"), target_client)
		// virtual std::string arranger(Client *source, Client *target);
		// virtual std::string arranger(Client *source, Client *target, std::string parameter);
		// virtual std::string arranger(Client *source, Client *target, std::vector<std::string> parameters);
};

# endif


