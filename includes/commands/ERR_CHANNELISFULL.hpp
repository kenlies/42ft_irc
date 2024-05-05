#ifndef ERR_CHANNELISFULL_HPP
# define ERR_CHANNELISFULL_HPP

# include "ACommand.hpp"

class ERR_CHANNELISFULL : public ACommand {
	public:
		ERR_CHANNELISFULL(void);
		~ERR_CHANNELISFULL(void);

		ERR_CHANNELISFULL &operator=(ERR_CHANNELISFULL const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		ERR_CHANNELISFULL(ERR_CHANNELISFULL const &copy);
};

#endif