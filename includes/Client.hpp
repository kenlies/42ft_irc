#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "colors.h"
#include "Channel.hpp"
#include <iostream>
#include <vector>

class Client {

	public:

		// Constructors and destructors
		Client(int socket_fd);
		~Client(void);

		// Methods
		int		getSocketFd(void) const;

	private:

		// Canonical form
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		// Attributes
		int 					socket_fd;
		std::string				nickname;
		std::string				username;
		bool					registered;
		// std::vector<Channel *>	joinedChannels;


		// Methods

};

# endif
