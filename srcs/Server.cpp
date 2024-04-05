#include "Server.hpp"

Server::Server(char *port, char *password) {
	validate_port(port);
	validate_password(password);
	createListenSocket();
	commandsAvailable();
}

Server::~Server(void) {
}

void	Server::validate_port(char *port) {
	for (size_t i = 0; i < strlen(port); ++i) {
		if (!isdigit(port[i]))
			throw std::runtime_error("Error: Port must be a number!");
	}
	int p = atoi(port);
	if (p < 0 || p > 65535)
		throw std::runtime_error("Error: Port must be between 0 and 65536!");
	this->port = p;
}

void	Server::validate_password(char *password) {
	if (password[0]	== '\0')
		throw std::runtime_error("Error: Password cannot be empty!");
	if (std::string(password).find(' ') != std::string::npos)
		throw std::runtime_error("Error: Password cannot contain whitespace!");
	this->password = password;
}

void	Server::createListenSocket(void) {
	// Creating socket
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->serverSocket == -1)
		throw std::runtime_error("Error: Couldn't create server socket!");

	// Set socket options for reusing addresses and ports
	int yes = 1;
	if (setsockopt(this->serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1)
		throw std::runtime_error("Error: Couldn't set socket options!");

	// Specifying the address
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(this->port);

	// Binding socket
	if (bind(this->serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0)
		throw std::runtime_error("Error binding server socket");

	// Listening to the assigned socket
	if (listen(this->serverSocket, 5) < 0)
		throw std::runtime_error("Error listening on server socket");

	// Add server socket to the list of file descriptors to be polled
	pollfd serverPollfd;
	serverPollfd.fd = this->serverSocket;
	serverPollfd.events = POLLIN;
	pfds.push_back(serverPollfd);
}

void Server::run() {
    while (true) {
        // Poll for events on all file descriptors
		if (poll(pfds.data(), pfds.size(), -1) == -1)
    		throw std::runtime_error("Error: Poll failed!");

        // Iterate over all file descriptors, and handle events
		for (size_t i = 0; i < pfds.size(); ++i) {
            if (pfds[i].revents & POLLIN) {
                if (pfds[i].fd == serverSocket) {
                    handleNewConnection();
                }
				else {
					handleClientData(i);
				}
            }
        }
    }
	// Close the server socket when done
    close(serverSocket);
}

void Server::handleNewConnection() {
	// Accept the new client connection
	struct sockaddr_storage clientAddress;
	socklen_t clientAddressSize = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);
    if (clientSocket == -1)
        throw std::runtime_error("Error accepting client connection");

    // Add the client socket to the list of polled file descriptors
	pollfd clientPollfd;
	clientPollfd.fd = clientSocket;
	clientPollfd.events = POLLIN;
    pfds.push_back(clientPollfd);

	clients.push_back(new Client(clientSocket));

	//GONNA DELETE THE BELOW CODE

	// Print the new client connection
	std::cout << GREEN << "New client connected: " << clientSocket << RESET << std::endl;

    // Send welcome message to the client
    std::string message = ":IRC 001 :Welcome, " + std::to_string(clientSocket) + "!\r\n";
    send(clientSocket, message.c_str(), message.length(), 0);
}

void Server::handleClientData(size_t pollFdIndex) {
	//client is the client that sent the message
// 	Client *client = getClient(pfds[pollFdIndex].fd);
//  (void)client;
	// Receive data from the client
    char buffer[512] = { 0 };
    int nbytes = recv(pfds[pollFdIndex].fd, buffer, sizeof(buffer) - 1, 0);
    if (nbytes <= 0) {
		// Print the client disconnection
		std::cout << RED << "Client disconnected: " << pfds[pollFdIndex].fd << RESET << std::endl;
		close(pfds[pollFdIndex].fd);
		pfds.erase(pfds.begin() + pollFdIndex);
		return ;
    }

    // Print received message
    std::cout << BLUE << "Message from client: " RESET << buffer << std::endl;

	std::string message = buffer;
	parseMessage(message);
	// ACommand command(message, client);
	executeCommand();


    std::string response = BLUE "Received this: " RESET;
    response += buffer;
    send(pfds[pollFdIndex].fd, response.c_str(), response.length(), 0);
}


Client *Server::getClient(int socket_fd) {
	for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it) {
		if ((*it)->getSocketFd() == socket_fd)
			return (*it);
	}
	return (NULL);
}

void Server::commandsAvailable(void) {
	commandList.push_back("CAP");	// Capability list
}

void Server::executeCommand() {
	if (splittedMessage.empty())
		return ;
	std::string commandName = splittedMessage[0];
	if (std::find(commandList.begin(), commandList.end(), commandName) != commandList.end()) {
		std::cout << "Command " << commandName << " is available!" << std::endl;
	}
	else {
		std::cout << "Command " << commandName << " is not available!" << std::endl;
	}
	splittedMessage.clear();
}

void Server::parseMessage(std::string message) {
//split them based on the spaces
	std::stringstream ss(message);
	std::string word;
	while (ss >> word) {
		splittedMessage.push_back(word);
	}
}
