#ifndef CAP_HPP
# define CAP_HPP

#include "ACommand.hpp"
#include <memory>

class CAP : public ACommand {

	public:
		// Constructors and destructors
		CAP(Server *s);
		~CAP(void);

		// Methods
		void execute(std::string message, Client *client);

	private:

		// Canonical form
		CAP(void);
		CAP(CAP const &copy);
		CAP &operator=(CAP const &copy);

		// Attributes

		// Methods
		std::string arranger();

};



# endif
