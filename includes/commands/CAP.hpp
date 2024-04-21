#ifndef CAP_HPP
# define CAP_HPP

#include "ACommand.hpp"
#include <memory>

class CAP : public ACommand {

	public:
		CAP(Commands *c);
		~CAP(void);

		CAP &operator=(CAP const &copy);

		void handleCommand(std::string message, Client *source);
		std::string arranger(void);

	private:
		CAP(void);
		CAP(CAP const &copy);
};

# endif
