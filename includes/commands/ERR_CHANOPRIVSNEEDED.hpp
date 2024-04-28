#ifndef ERR_CHANOPRIVSNEEDED_HPP
# define ERR_CHANOPRIVSNEEDED_HPP

# include "ACommand.hpp"

class ERR_CHANOPRIVSNEEDED : public ACommand {
	public:
		ERR_CHANOPRIVSNEEDED(void);
		~ERR_CHANOPRIVSNEEDED(void);

		ERR_CHANOPRIVSNEEDED &operator=(ERR_CHANOPRIVSNEEDED const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		ERR_CHANOPRIVSNEEDED(ERR_CHANOPRIVSNEEDED const &copy);
};

#endif
