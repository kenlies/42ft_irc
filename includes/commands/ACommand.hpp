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
		virtual ~ACommand(void);

		// Methods
		virtual void	execute(std::string message) = 0;
		void			parseMessage(std::string message);

	protected:

		// Canonical form
		ACommand(ACommand const &copy);
		ACommand &operator=(ACommand const &copy);

		// Attributes
		std::vector<std::string> parameters;

		// Methods
};

# endif
