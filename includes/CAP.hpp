#ifndef CAP_HPP
# define CAP_HPP

#include "ACommand.hpp"
#include <memory>

class CAP {

	public:
		// Constructors and destructors
		CAP(void);
		~CAP(void);

		// Methods
		void execute();

	private:

		// Canonical form
		CAP(CAP const &copy);
		CAP &operator=(CAP const &copy);

		// Attributes

		// Methods


};



# endif
