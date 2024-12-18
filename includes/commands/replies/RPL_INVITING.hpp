#ifndef RPL_INVITING_HPP
# define RPL_INVITING_HPP

# include "ACommand.hpp"

class RPL_INVITING : public ACommand {
	public:
		RPL_INVITING(void);
		~RPL_INVITING(void);

		RPL_INVITING &operator=(RPL_INVITING const &copy);

		std::string const	arranger(Client *source, Client *target, Channel *channel) const;

	private:
		RPL_INVITING(RPL_INVITING const &copy);
};

#endif
