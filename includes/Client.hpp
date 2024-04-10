#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "colors.h"
#include "Channel.hpp"
#include <iostream>
#include <vector>

class Client {

	public:

		// Constructors and destructors
		Client(int socketFd);
		~Client(void);

		// Methods
		int		getSocketFd(void);
		void 	addBufferToMsgBuffer(std::string buffer);
		bool	validMessage(void);
		std::string getMsgBuffer(void);

	private:

		// Canonical form
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		// Attributes
		int 					socketFd;
		std::string				msgBuffer;
		std::string				nickname;
		std::string				username;
		bool					registered;
		// std::vector<Channel *>	joinedChannels;


		// Methods

};

# endif
