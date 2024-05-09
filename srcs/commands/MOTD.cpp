#include "MOTD.hpp"

MOTD::MOTD(Commands *c) {
	commands = c;
	command = "MOTD";
}

MOTD::~MOTD(void) {
}

MOTD &MOTD::operator = (MOTD const &copy) {
	(void)copy;
	return (*this);
}

void MOTD::handleCommand(std::string const message, Client *source) {
	(void)message;

	std::vector<std::string> motd = getRandomMotd();

	if (motd.empty())
		commands->sendCommand(commands->errNoMotd->arranger(source), source);

	else {
		commands->sendCommand(commands->rplMotdStart->arranger(source), source);
		for (std::string line : motd) {
			commands->sendCommand(commands->rplMotd->arranger(source, line), source);
		}
		commands->sendCommand(commands->rplEndOfMotd->arranger(source), source);
	}
}

std::string const MOTD::arranger() const {
	return (this->command);
}

std::vector<std::string> const MOTD::getRandomMotd(void) const {
	std::vector<std::vector <std::string>> const motds = {
	{
	"  ___ ___  ___   ___  _____   _____",
	" |_ _| _ \\/ __| | _ )/ _ \\ \\ / / __|",
	"  | ||   / (__  | _ \\ (_) \\ V /\\__ \\",
	" |___|_|_\\\\___| |___/\\___/ |_| |___/",
	"                                    "
	}
	};

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, motds.size() - 1);

	return (motds[distr(gen)]);
}
