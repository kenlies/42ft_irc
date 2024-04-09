#include "CAP.hpp"

CAP::CAP(void) {
}

CAP::~CAP(void) {
}

void CAP::execute(std::string message) {
	std::cout << "CAP command: Message: " << message << std::endl;
}
