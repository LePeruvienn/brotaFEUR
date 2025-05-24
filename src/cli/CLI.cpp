#include <string>
#include <iostream>
#include "CLI.h"
#include "Console.h"
#include "Command.h"

/** @module CLI */
namespace CLI {

	std::atomic<bool> running = true; ///< Is the CLI thread running

	/** Private Namespace */
	namespace {

		bool exitCLI = false; ///< Exit CLI condition
	}

	/*
	* CLI main thread function
	*/
	void run() {

		// Run Console::log tests
		// Console::showAllColors();
		// Console::showAllStyles();

		// User string input var
		std::string input;

		// Run the thread until we stop it
		while (running) {

			// If we must exit CLI loop we break
			if (exitCLI)
				break;

			// Show string entry input
			std::cout << "> ";

			// Wait for user input
			std::getline(std::cin, input);

			// Run CLI input !
			std::string commandError = runCommand(input);

			// Check if we have returned an error
			if (!commandError.empty())	
				// Show error in this case
				Console::logError(commandError);
		}
	}

	/*
	 * Exit CLI loop
	 */
	void exit() {
		// Set exitCLI to TRUE
		exitCLI = true;
	}
}

