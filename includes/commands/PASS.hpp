#ifndef PASS_HPP
# define PASS_HPP

#include "ACommand.hpp"
#include "Commands.hpp"
#include <memory>

class PASS : public ACommand {

	public:
		// Constructors and destructors
		PASS(void);
		PASS(Commands *c);
		~PASS(void);

		// Methods
		void execute(std::string message, Client *source);

		PASS &operator=(PASS const &copy);
	private:

		// Canonical form
		PASS(PASS const &copy);

		// Attributes

		// Methods
		std::string arranger();

};

# endif
