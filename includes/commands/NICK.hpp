#ifndef NICK_HPP
# define NICK_HPP

#include "ACommand.hpp"
#include <memory>

class NICK : public ACommand {

	public:
		NICK(Commands *c);
		~NICK(void);

		NICK &operator=(NICK const &copy);

		void handleCommand(std::string message, Client *source);
		std::string arranger(void);

	private:
		NICK(void);
		NICK(NICK const &copy);
};

# endif
