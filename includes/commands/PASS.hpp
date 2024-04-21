#ifndef PASS_HPP
# define PASS_HPP

# include "ACommand.hpp"

class PASS : public ACommand {
	public:
		PASS(Commands *c);
		~PASS(void);

		PASS &operator=(PASS const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(void);

	private:
		PASS(void);
		PASS(PASS const &copy);
};

#endif
