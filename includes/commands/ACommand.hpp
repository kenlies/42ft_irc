#ifndef	ACOMMAND_HPP
# define ACOMMAND_HPP

# include "colors.h"
# include "Client.hpp"
# include <iostream>
# include <string>
# include <sstream>

class Commands;

class ACommand {
	public:
		ACommand(void);
		virtual ~ACommand(void);

		virtual void	handleCommand(std::string message, Client *source);

		std::vector<std::string>	parseMessage(std::string message);

	protected:
		std::string		command;
		Commands		*commands;

	private:
		ACommand(ACommand const &copy);
		ACommand &operator=(ACommand const &copy);
};

# include "Commands.hpp"

#endif
