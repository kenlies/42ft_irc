#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
// #include "Server.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <sys/socket.h>

class Server;

class ACommand {

	public:

		// Constructors and destructors
		ACommand(void);
		ACommand &operator=(ACommand const &copy);
		virtual ~ACommand(void);

		// Methods
		virtual void	execute(std::string message, Client *client) = 0;
		void			parseMessage(std::string message);
		// void			sendMsg(std::string message, Client *source, Client *target);
		// void			sendMsg(std::string message, Client *source, Channel *target);
		void			sendMsg(std::string message, Client *target);
		// void			sendMsg(std::string message, Channel *target);
		// void			sendMsg(std::string message, Client *source);
		// void			sendMsg(std::string message);

	protected:

		// Canonical form
		ACommand(ACommand const &copy);

		// Attributes
		Server						*server;
		std::vector<std::string>	parameters;

		// Methods
		virtual std::string arranger(std::string message);
};

# endif
