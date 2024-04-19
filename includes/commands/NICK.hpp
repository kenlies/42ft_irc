#ifndef NICK_HPP
# define NICK_HPP

#include "ACommand.hpp"
#include <memory>

class NICK : public ACommand {

	public:
		// Constructors and destructors
	//	NICK(Server *s);
		~NICK(void);

		// Methods
		void execute(std::string message, Client *client);
		NICK(void);

	private:

		// Canonical form
		NICK(NICK const &copy);
		NICK &operator=(NICK const &copy);

		// Attributes

		// Methods
		std::string arranger();


};



# endif
