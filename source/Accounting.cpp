#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "check.h"
#include "processing.h"

int main() {
	std::string cmd;
	
	while (1) {
		std::cout << ">> ";
		getline(std::cin, cmd);

		if (cmd == "exit")
			break;

		processing(cmd);
	}

	return 0;
}