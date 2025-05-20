#include <vector>
#include "Command.h"
#include "Console.h"

/* @module CLI */
namespace CLI {

	/*
	 * >>> Private namespace functions !!
	 *
	 * Here we have all the function command we can run with the CLI !
	 * They are declared in a private namespace to avoid being used without entry
	 *
	 * All commands are declared with a string array that are all the user inputs parameters
	 *
	 * - If a function has been run succefully it return 0
	 * - If not it returns 1
	 *
	 * The @param in comments are the ones used in the CLI, not the function !!!
	 */
	namespace {

		/*
		 * Exit the current game to desktop
		 */
		int exit(std::vector<std::string> parameters) {

			// TODO

			return 0;
		}
	}

	/*
	 * Run the command in parameter
	 */
	int runCommand(const std::string& command) {

		// TODO

		return 0;
	}
}
