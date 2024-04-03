#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include "colors.h"
#include "Client.hpp"
#include <iostream>
#include <vector>

class Channel {

	public:

		// Constructors and destructors
		Channel(void);
		~Channel(void);

		// Methods

	private:

		// Canonical form
		Channel(Channel const &copy);
		Channel &operator=(Channel const &copy);

		// Attributes
		std::string				name;
		int						id; // not sure if we are gonna keep this!
		std::string				topic;
		std::string				mode;
		// std::vector<Client *>	clients;
		// std::vector<Client *>	operators;

		// Methods

};

# endif
