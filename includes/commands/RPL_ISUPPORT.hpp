#ifndef RPL_ISUPPORT_HPP
# define RPL_ISUPPORT_HPP

# include "ACommand.hpp"

class RPL_ISUPPORT : public ACommand {
	public:
		RPL_ISUPPORT(void);
		~RPL_ISUPPORT(void);

		RPL_ISUPPORT &operator=(RPL_ISUPPORT const &copy);

		std::string	arranger(Client *source, std::string token);

	private:
		RPL_ISUPPORT(RPL_ISUPPORT const &copy);
};

#endif