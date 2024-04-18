#include <iostream>
#include "Server.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 3)
			throw std::runtime_error("Usage: ./server <port> <password>");
		Server server(argv[1], argv[2]);
		server.run();
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return (1);
	}
	return (0);
}

