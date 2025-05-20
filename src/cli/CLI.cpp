#include <string>
#include <iostream>
#include "CLI.h"
#include "Command.h"

/** @module CLI */
namespace CLI {

	std::atomic<bool> running = true; ///< Is the CLI thread running

	/*
	* CLI main thread function
	*/
	void run() {

		// User string input var
		std::string input;

		// Run the thread until we stop it
		while (running) {

			// Show string entry input
			std::cout << "> ";

			// Wait for user input
			std::getline(std::cin, input);

			// Run CLI input !
			runCommand(input);
		}
	}
}

