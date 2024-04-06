#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
// #include "Server.hpp"
#include <iostream>
#include <string>
#include <sstream>

class Server;

class ACommand {

	public:

		// Constructors and destructors
		ACommand(void);
		~ACommand(void);

		// Methods
		std::string	getCommand(void) const;
		void	parseMessage(std::string message);
		// virtual void execute() = 0;

	protected:

		// Canonical form
		ACommand(ACommand const &copy);
		ACommand &operator=(ACommand const &copy);

		// Attributes
		std::string message;
		std::string command;
		std::vector<std::string> parameters;

		// Methods
};

# endif
