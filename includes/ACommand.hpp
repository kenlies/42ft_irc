#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

#include "colors.h"
#include "Client.hpp"
#include "Channel.hpp"
// #include "Server.hpp"
#include <iostream>
#include <string>

class Server;

class ACommand {

	public:

		// Constructors and destructors
		ACommand(void);
		virtual ~ACommand(void);

		// Methods

	protected:

		// Canonical form
		ACommand(ACommand const &copy);
		ACommand &operator=(ACommand const &copy);

		// Attributes

		// Methods

};

# endif
