#include "Server.hpp"

Server::Server(char *port, char *password) {
	validate_port(port);
	validate_password(password);
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

void	Server::run(void) {
	// Creating socket
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	// Specifying the address
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(this->port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	// Binding socket
	bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

	// Listening to the assigned socket
	listen(serverSocket, 5);

	std::vector<pollfd> pfds;
	pollfd serverPollfd;
	serverPollfd.fd = serverSocket;
	serverPollfd.events = POLLIN;
	pfds.push_back(serverPollfd);

	while (true) {
		poll(pfds.data(), pfds.size(), -1);
		for (size_t i = 0; i < pfds.size(); ++i) {
			if (pfds[i].revents & POLLIN) {
				if (pfds[i].fd == serverSocket) {
					int clientSocket = accept(serverSocket, nullptr, nullptr);
					if (clientSocket == -1) {
						std::cerr << "Error accepting client connection" << std::endl;
						continue;
					}
					pollfd clientPollfd;
					clientPollfd.fd = clientSocket;
					clientPollfd.events = POLLIN;
					pfds.push_back(clientPollfd);
					// Send welcome message
					std::string message = ":IRC 001 :Welcome, " + std::to_string(clientSocket) + "!\r\n";
					send(clientSocket, message.c_str(), message.length(), 0);
				}
				else {
					char buffer[512] = { 0 };
					int nbytes = recv(pfds[i].fd, buffer, sizeof(buffer) - 1, 0);
					if (nbytes <= 0)
					{
						close(pfds[i].fd);
						pfds.erase(pfds.begin() + i);
						--i;
					}
					else {
						std::cout << "Message from client: " << buffer << std::endl;

						std::string command = buffer;

						std::string response = "Received this: ";
						response += buffer;
						send(pfds[i].fd, response.c_str(), response.length(), 0);
					}
				}
			}
		}
	}
	close(serverSocket);
}
