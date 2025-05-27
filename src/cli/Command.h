#include <string>
#include <functional>
#include <unordered_map>

/*
 * All the commands we can run defined by types,
 * They are linked to a string that is the first input you must write to run this command.
 *
 * All the commands you can run are defined in `Command.cpp` !
 *
 * `runCommand()` method is used to parse a user input to a command we run
 */
enum CommandType {
	Exit
};

/* @module CLI */
namespace CLI {

	/*
	 * All the linked string to the enum CommandType
	 * IMPORTANT: All the strings must be in the same index of the enum
	 */
	const std::string CommandToString[] = {
		"exit"
	};

	// Where all the commands are stored
	extern std::unordered_map<std::string, std::function<std::string(std::istringstream&)>> commands;

	/*
	 * Run the command in parameter, return an error if something as occured
	 * @param const string& - the command we want to run
	 * @return string - the error message, or "" if all is OK
	 */
	std::string runCommand(const std::string& command);
}
