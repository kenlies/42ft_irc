#ifndef PASS_HPP
# define PASS_HPP

#include "ACommand.hpp"
#include <memory>

class PASS : public ACommand {

	public:
		// Constructors and destructors
		PASS(Server *s);
		~PASS(void);

		// Methods
		void execute(std::string message, Client *client);

	private:

		// Canonical form
		PASS(void);
		PASS(PASS const &copy);
		PASS &operator=(PASS const &copy);

		// Attributes

		// Methods
		std::string arranger();

};

# endif
