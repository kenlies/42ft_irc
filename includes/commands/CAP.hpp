#ifndef CAP_HPP
# define CAP_HPP

#include "ACommand.hpp"
#include <memory>

class CAP : public ACommand {

	public:
		// Constructors and destructors
		CAP(void);
	//	CAP(Commands *c);
		~CAP(void);

		// Methods
		void execute(std::string message, Client *source);

	private:

		// Canonical form
		CAP(CAP const &copy);
		CAP &operator=(CAP const &copy);

		// Attributes

		// Methods
		std::string arranger();

};



# endif
