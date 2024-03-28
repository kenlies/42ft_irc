#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "colors.h"
#include "Channel.hpp"
#include <iostream>
#include <vector>

class Client {

	public:

		// Constructors and destructors
		Client(void);
		~Client(void);

		// Methods

	private:

		// Canonical form
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		// Attributes
		int 					socket; // not sure if it should be an int!
		std::string				nickname;
		std::string				username;
		// std::vector<Channel *>	joinedChannels;


		// Methods

};

# endif
