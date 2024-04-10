#ifndef SERVER_HPP
# define SERVER_HPP

#include "colors.h"
#include "CAP.hpp"
#include "NICK.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ACommand.hpp"
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <fcntl.h>
#include <map>
#include <regex>
#include <memory>
#include <iomanip>

class Server {

	public:
		// Constructors and destructors
		Server(char *port, char *password);
		~Server(void);

		// Methods
		void	run(void);

	private:

		// Canonical form
		Server(void);
		Server(Server const &copy);
		Server &operator=(Server const &copy);

		// Attributes
		unsigned int			port;
		std::string				password;
		int						serverSocket;
		std::vector<pollfd> 	pfds;
		std::vector<Client *>	clients;
		std::vector<Channel *>	channels;
		std::map<std::string, std::unique_ptr<ACommand>> commandList;

		// Methods
		void	validatePort(char *port);
		void	validatePassword(char *password);
		void	commandsAvailable(void);
		void	createListenSocket(void);
		void	handleNewConnection();
		void	handleClientData(size_t pollFdIndex);
		void	executeCommand(std::string message);
		std::pair<std::string, std::string> validateCommand(std::string message);
		Client	*getClientBySocketFd(int socketFd);


};

# endif
