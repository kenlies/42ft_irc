#include "NICK.hpp"

NICK::NICK(Commands *c) {
	commands = c;
	command = "NICK";
	requireRegistration = false;
}

NICK::~NICK(void) {
}

NICK &NICK::operator = (NICK const &copy) {
	(void)copy;
	return (*this);
}

void NICK::handleCommand(std::string const message, Client *source) {
	std::vector<std::string> parameters;
	if (!message.empty()) {
		try {
			parameters = parseMessage(message);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding parameters to the list has failed", source), source);
			return ;
		}
	}

	if (parameters.empty())
		commands->sendCommand(commands->errNoNicknameGiven->arranger(source), source);
	else if (validateNickname(parameters[0])) {
		if (commands->server->nickExists(parameters[0]))
			commands->sendCommand(commands->errNicknameInUse->arranger(parameters[0], source), source);
		else {
			if (source->getValidPass()) {
				commands->sendCommand(arranger(parameters[0]), source, source);
				for (std::pair<std::string, Channel *> chanPair : source->getJoinedChannels()) {
					commands->sendCommand(arranger(parameters[0]), source, chanPair.second, source);
				}
				source->setNickname(parameters[0]);
				if (source->tryToRegister())
					commands->registrationReply(source);
			}
			else
				commands->sendCommand(commands->errPasswMismatch->arranger(source), source);
		}
	}
	else
		commands->sendCommand(commands->errErroneusNickname->arranger(parameters[0], source), source);
}

std::string const NICK::arranger(std::string const newNickname) const {
	return (this->command + " " + newNickname);
}

bool NICK::validateNickname(std::string &input) {
	size_t				i = 0;
	const size_t 		maxNickLen = 12;
	const std::string	characters = "[]{}\\|_";

	while (std::isalnum(input[i]) || characters.find(input[i]) != std::string::npos) {
		i++;
	}
	if (i != input.size())
		return (false);

	if (input.size() > maxNickLen)
		input.resize(maxNickLen);

	return (true);
}
