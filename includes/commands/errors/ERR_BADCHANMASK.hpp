#ifndef ERR_BADCHANMASK_HPP
# define ERR_BADCHANMASK_HPP

# include "ACommand.hpp"

class ERR_BADCHANMASK : public ACommand {
	public:
		ERR_BADCHANMASK(void);
		~ERR_BADCHANMASK(void);

		ERR_BADCHANMASK &operator=(ERR_BADCHANMASK const &copy);

		std::string const	arranger(std::string const channel) const;

	private:
		ERR_BADCHANMASK(ERR_BADCHANMASK const &copy);
};

#endif
