#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

#include "ACommand.hpp"
#include <memory>

class ERR_NEEDMOREPARAMS : public ACommand {

	public:
		// Constructors and destructors
		ERR_NEEDMOREPARAMS(Server *s);
		~ERR_NEEDMOREPARAMS(void);

		// Methods
		void execute(std::string message, Client *client);

	private:

		// Canonical form
		ERR_NEEDMOREPARAMS(void);
		ERR_NEEDMOREPARAMS(ERR_NEEDMOREPARAMS const &copy);
		ERR_NEEDMOREPARAMS &operator=(ERR_NEEDMOREPARAMS const &copy);

		// Attributes

		// Methods
		std::string arranger();

};

# endif
