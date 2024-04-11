#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "colors.h"
#include <iostream>

#define MSG_BUFFER_SIZE 512

class Client {

	public:

		// Constructors and destructors
		Client(int socketFd);
		~Client(void);

		// Methods
		void 		addBufferToMsgBuffer(std::string buffer);
		bool		msgCompleted(void);

		// Getters
		int			getSocketFd(void);
		std::string getMsgFromBuffer(void);

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
