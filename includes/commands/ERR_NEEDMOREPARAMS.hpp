#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

#include "ACommand.hpp"
#include <memory>

class ERR_NEEDMOREPARAMS : public ACommand {

	public:
		// Constructors and destructors
		ERR_NEEDMOREPARAMS(void);
		~ERR_NEEDMOREPARAMS(void);

		// Methods
		void		execute(std::string message, Client *source);
		std::string	arranger();

		ERR_NEEDMOREPARAMS &operator=(ERR_NEEDMOREPARAMS const &copy);

	private:

		// Canonical form
		ERR_NEEDMOREPARAMS(ERR_NEEDMOREPARAMS const &copy);

		// Attributes

		// Methods

};

# endif
