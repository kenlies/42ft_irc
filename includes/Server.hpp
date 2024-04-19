#ifndef SERVER_HPP
# define SERVER_HPP

//FIXME: Please check if I am neccessary!
#include "colors.h"
#include "Channel.hpp"
#include "Client.hpp"
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
#include <iomanip>
#include <algorithm>

class Commands;

class Server {

	public:
		// Constructors and destructors
		Server(char *port, char *password);
		~Server();

		// Methods
		void	run();
	//	void	addCommandToList(std::string name, ACommand *command);
	//	ACommand *getCommandFromList(std::string command);

	private:

		// Canonical form
		Server();
		Server(Server const &copy);
		Server &operator=(Server const &copy);

		// Attributes
		unsigned int			port;
		std::string				password;
		int						serverSocket;
		std::vector<pollfd> 	pfds;
		std::vector<Client *>	clients;
		std::vector<Channel *>	channels;
		Commands				*commands;

		// Methods
		void	validatePort(char *port);
		void	validatePassword(char *password);
		//void	initCommandList();
		void	initListenSocket();
		void	handleNewConnection();
		void	handleClientData(size_t pollFdIndex);
		void	parseMsg(std::string message, Client *client);
		Client	*getClientBySocketFd(int socketFd);



};

#include "Commands.hpp"

# endif
