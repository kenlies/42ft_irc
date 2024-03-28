#ifndef	COMMAND_HPP
# define COMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
#include <iostream>
#include <string>

class Command {

	public:

		// Constructors and destructors
		Command(std::string command, Client *client, Channel *channel);
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

};

# endif
