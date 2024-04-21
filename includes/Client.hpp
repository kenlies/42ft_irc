#ifndef CLIENT_HPP
# define CLIENT_HPP

# define MSG_BUFFER_SIZE 512

# include "colors.h"
# include <iostream>
# include <unordered_set>

class Client {
	public:
		Client(int socketFd);
		~Client(void);

		void 		addBufferToMsgBuffer(std::string buffer);
		bool		msgCompleted(void);
		bool		isAllowedUserMode(char mode);
		bool		addMode(char mode);
		bool		delMode(char mode);
		bool		hasMode(char mode);

		int			getSocketFd(void);
		std::string	getMsgFromBuffer(void);

	private:
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		int 							socketFd;
		std::string						msgBuffer;
		std::string						nickname;
		std::string						username;
		std::unordered_set<char>		userMode;
		// std::vector<Channel *>	joinedChannels;
};

#endif
