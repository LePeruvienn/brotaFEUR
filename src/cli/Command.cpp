#include <sstream>
#include "Command.h"
#include "Console.h"

/* @module CLI */
namespace CLI {

	/*
	 * >>> Map of all the commands linked to there function
	 *
	 * Here we have all the function command we can run with the CLI !
	 *
	 * All commands are declared with a string buffer that are all the user inputs parameters
	 *
	 * - If a function has been run succefully it return 0
	 * - If not it returns 1
	 */
	std::unordered_map<std::string, std::function<int(std::istringstream&)>> commands = {

		/*
		 * Function used to exit the game 
		 * @param : None
		 */
		{"exit", [](std::istringstream& parameters) {

			Console::log("RUN COMMAND EXIT");

			// Command has run succefully, we can return 0
			return 0;
		}}
	};

	/*
	 * Run the command in parameter
	 */
	int runCommand(const std::string& command) {

		// Get current commands as a string buffer list
		std::istringstream iss(command);

		// Extract the command name from string buffer
		std::string commandName;
		iss >> commandName;

		// We check if the cmd name is in the list
		if (commands.find(commandName) != commands.end())
			// If he is in the list we run the command
			return commands[commandName](iss);

		// Return 1 cause we dont find any linked command
		return 1;
	}
}
