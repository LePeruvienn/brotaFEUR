#include <sstream>
#include <iostream>
#include "Command.h"
#include "Console.h"

#include "CLI.h"
#include "../core/Game.h"

/* @module CLI */
namespace CLI {

	const std::string __EMPTY_STRING__ = ""; ///< Empty string const

	/*
	 * >>> Map of all the commands linked to there function
	 *
	 * Here we have all the function command we can run with the CLI !
	 *
	 * All commands are declared with a string buffer that are all the user inputs parameters
	 *
	 * - If a function has been run succefully it return an empty string : ""
	 * - If not it returns an error that is describe in a string
	 *
	 * TODO: The structure is not that good, to improve
	 */
	std::unordered_map<std::string, std::function<std::string(std::istringstream&)>> commands = {

		/*
		 * Exit the game
		 * @param : None
		 */
		{"exit", [](std::istringstream& parameters) {

			Console::logWarning("Exiting Game ...");

			// Exit game
			Game::exit();

			// Exit CLI loop
			CLI::exit();

			// Command has run succefully, we can return 0
			return __EMPTY_STRING__;
		}},

		/*
		 * Switch the game to the current scene
		 * @params :
		 * - sceneName - the name of the scene we want to switch
		 */
		{"scene", [](std::istringstream& parameters) {

			// Get the next argument (wich is the scene name)
			std::string sceneName;
			parameters >> sceneName;

			// Show message
			std::string message = "Setting scene to" + sceneName;
			Console::logInfo(message);

			// Switching scene
			Game::setScene(sceneName);

			// Command has run succefully, we can return 0
			return __EMPTY_STRING__;
		}},

		/*
		 * Switch the game to the current scene
		 * @params :
		 * - sceneName - the name of the scene we want to switch
		 */
		{"clear", [](std::istringstream& parameters) {

			// Get first argument (nb of line to delete)
			std::string argument;
			parameters >> argument;

			// If there is no argument we just want to do a basic clear
			if (argument.empty()) {
				// Clear all the scren
				std::cout << "\033[2J\033[H";
				// Stop here
				return __EMPTY_STRING__;
			}

			// Set error message var
			std::string errorMessage;

			try {
				// Parse argument to integer
				int count = std::stoi(argument);

				// Clear the amount of line in parameter
				for (int i = 0; i < count + 1; i++)
					// Move cursor up & Clear entire line
					std::cout << "\033[A" << "\033[2K";

				// Return to beginning of current line
				std::cout << "\r";
				
			} catch (const std::invalid_argument& error) {
				// Set error message
				errorMessage = "Invalid input";

			} catch (const std::out_of_range& error) {
				// Set error message
				errorMessage = "Out of range";
			}

			// Command has run succefully, we can return 0
			return errorMessage;
		}}
	};

	/*
	 * Run the command in parameter, return an error if something as occured
	 * @param const string& - the command we want to run
	 * @return string - the error message, or "" if all is OK
	 */
	std::string runCommand(const std::string& command) {

		// Get current commands as a string buffer list
		std::istringstream iss(command);

		// Extract the command name from string buffer
		std::string commandName;
		iss >> commandName;

		// We check if the cmd name is in the list
		if (commands.find(commandName) != commands.end())
			// If he is in the list we run the command
			return commands[commandName](iss);

		// Return ERROR cause we dont found any linked command
		return "Unknown Command";
	}
}
