#ifndef SERVER_HPP
# define SERVER_HPP

#include "colors.h"
#include "CAP.hpp"
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
#include <memory>

class Server {

		// typedef void(*cmd)();
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
		std::vector<Channel *>	channels;
		std::vector<Client *>	clients;


		std::map<std::string, std::unique_ptr<void>> commandList;
		// ACommand				*command;


		// Methods
		void	validate_port(char *port);
		void	validate_password(char *password);
		void	commandsAvailable(void);
		void	createListenSocket(void);
		void	handleNewConnection();
		void	handleClientData(size_t pollFdIndex);

		Client	*getClient(int socket_fd);
		// void	executeCommand();

};

# endif
