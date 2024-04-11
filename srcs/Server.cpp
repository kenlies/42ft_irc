#include "Server.hpp"

Server::Server(char *port, char *password) {
	validatePort(port);
	validatePassword(password);
	initListenSocket();
	initCommandList();
}

Server::~Server() {
}

void	Server::validatePort(char *port) {
	for (size_t i = 0; i < strlen(port); ++i) {
		if (!std::isdigit(port[i]))
			throw std::runtime_error("Error: Port must be a number!");
	}
	int p = std::atoi(port);
	if (p < 0 || p > 65535)
		throw std::runtime_error("Error: Port must be between 0 and 65536!");
	this->port = p;
}

void	Server::validatePassword(char *password) {
	if (password[0]	== '\0')
		throw std::runtime_error("Error: Password cannot be empty!");
	if (std::string(password).find(' ') != std::string::npos)
		throw std::runtime_error("Error: Password cannot contain whitespace!");
	this->password = password;
}

void	Server::initListenSocket() {
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

void	Server::initCommandList() {
		commandList["CAP"] = new CAP();
        commandList["NICK"] = new NICK();
		//FIXME: Delete me (commandList) in the destructor, please I dont wanna live forever!
}

void	Server::run() {
    while (true) {
        // Poll for events on all sockets
		// FIXME: should we exit on poll failure, or poll will be fixed??
		if (poll(pfds.data(), pfds.size(), -1) == -1)
    		throw std::runtime_error("Error: Poll failed!");

        // Iterate over all sockets, and handle events
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

	// Print the new client connection
	std::cout << GREEN << "New client connected: " << clientSocket << RESET << std::endl;

	//GONNA DELETE THE BELOW CODE
    // Send welcome message to the client
    std::string message = ":IRC 001 :Welcome, " + std::to_string(clientSocket) + "!\r\n";
    send(clientSocket, message.c_str(), message.length(), 0);
}

void Server::handleClientData(size_t pollFdIndex) {
	//get client from the list of clients based on the pollFdIndex
	Client *client = getClientBySocketFd(pfds[pollFdIndex].fd);
	// Receive data from the client
    char buffer[512] = { 0 };
    int nbytes = recv(pfds[pollFdIndex].fd, buffer, sizeof(buffer) - 1, 0);
    if (nbytes <= 0) {
		// Print the client disconnection
		std::cout << RED << "Client disconnected: " << pfds[pollFdIndex].fd << RESET << std::endl;
		close(pfds[pollFdIndex].fd);
		pfds.erase(pfds.begin() + pollFdIndex);

		//FIXME: Destructor will handle removal of the client from everywhere! // keep the line below for now!
		clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
		return ;
    }
	client->addBufferToMsgBuffer(buffer);
	while (client->msgCompleted()) {
		parseMsg(client->getMsgFromBuffer());
	}

	//DELETE THIS IN THE END, ALSO SEND IS GONNA BE INSIDE EACH COMMAND!
    std::string response = BLUE "Received this: " RESET;
    response += buffer;
    send(pfds[pollFdIndex].fd, response.c_str(), response.length(), 0);
}

// Checks if the command is valid and checks if it can find in the commandList
void Server::parseMsg(std::string message) {
	//just check if the message is empty, it has not command to execute!
	if (message.empty())
		return ;

	// make sure we only have ASCII SPACEs and no other whitespace
	for (char c : message) {
		if (std::isspace(c) && c != ' ') {
			// FIXME: Handle whitespace errors properly!
			std::cout << "Error: Found other whitespace characters!" << std::endl;
			return ;
		}
	}

	// split command from parameters
    std::stringstream ss(message);
    std::string command, restOfMessage;
	ss >> command;
	std::getline(ss, restOfMessage);

	// remove spaces from the beginning of parameters
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos)
		restOfMessage = restOfMessage.substr(restOfMessage.find_first_not_of(' '));

	// execute command if found, or return error
	if (commandList.find(command) != commandList.end()) {
		commandList[command]->execute(restOfMessage);
	}
	else {
		// FIXME: Handle invalid commands properly!
		std::cout << "Command " << command << " is not available!" << std::endl;
	}
}

Client *Server::getClientBySocketFd(int socketFd) {
	for (size_t i = 0; i < clients.size(); ++i) {
		if (clients[i]->getSocketFd() == socketFd)
			return clients[i];
	}
	return nullptr;
}
