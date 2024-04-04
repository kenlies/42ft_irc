#ifndef	COMMAND_HPP
# define COMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
#include "Server.hpp"
#include <iostream>
#include <string>

class Command {

	public:

		// Constructors and destructors
		Command(void);
		Command(std::string message, Client *client);
		virtual ~Command(void);

		// Methods
		virtual void	run(void) = 0;

	private:

		// Canonical form
		Command(Command const &copy);
		Command &operator=(Command const &copy);

		// Attributes
		std::string	command;
		std::string message;
		Client		*client;
		Channel		*channel;

		// Methods
		std::vector<std::string> parseMessage(std::string message);

};

# endif
