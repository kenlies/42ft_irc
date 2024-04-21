#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <sys/socket.h>

class Commands;

class ACommand {

	public:

		// Constructors and destructors
		ACommand(void);
		ACommand &operator=(ACommand const &copy);
		virtual ~ACommand(void);

		// Methods
		virtual void			execute(std::string message, Client *source) = 0;
		virtual std::string		arranger() = 0;
		// virtual std::string 	arranger(std::string message) = 0;

	protected:

		// Canonical form
		ACommand(ACommand const &copy);

		// Attributes
		std::string					command;
		Commands					*commands;

		// Methods

		// generic arrangers that could have string or vector of strings as parameter to send as command parameters
		// We would use them something like this: sendMsg(arranger(source, target_client, "string"), target_client)
		// virtual std::string arranger(Client *source, Client *target);
		// virtual std::string arranger(Client *source, Client *target, std::string parameter);
		// virtual std::string arranger(Client *source, Client *target, std::vector<std::string> parameters);
};

#include "Commands.hpp"

# endif
