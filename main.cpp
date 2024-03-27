#include "colors.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <vector>
#include <string>

int main() {
    int port = 1337;

    // Creating socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Specifying the address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
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
					pollfd clientPollfd;
                    clientPollfd.fd = clientSocket;
                    clientPollfd.events = POLLIN;
                    pfds.push_back(clientPollfd);
                }
				else {
					char buffer[512] = { 0 };
					int nbytes = recv(pfds[i].fd, buffer, sizeof(buffer), 0);
					if (nbytes <= 0)
					{
						close(pfds[i].fd);
						pfds.erase(pfds.begin() + i);
					}
					else {
						std::cout << "Message from client: " << buffer << std::endl;

						std::string response = "Received this: ";
						response += buffer;
						send(pfds[i].fd, response.c_str(), response.length(), 0);
					}
				}
        	}
    	}
	}
	close(serverSocket);
	return 0;
}

