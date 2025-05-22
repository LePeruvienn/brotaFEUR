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

/*
 * All the linked string to the enum CommandType
 * IMPORTANT: All the strings must be in the same index of the enum
 */
const std::string CommandToString[] = {
	"exit"
};

/* @module CLI */
namespace CLI {

	// Where all the commands are stored
	extern std::unordered_map<std::string, std::function<int(std::istringstream&)>> commands;

	/*
	 * Run the command in parameter
	 * @param command - User input string that has been entered in the console
	 * @return integer - 0 if it run good, 1 if not 😢
	 */
	int runCommand(const std::string& command);
}
