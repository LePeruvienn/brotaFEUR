#include <string>

/*
 * Used to define all the possible log types
 */
enum LogType {
	Default,
	Error,
	Warning,
	Info,
	Success
};

/*
 * Struct used to store log datas before writing them into the log file
 */
struct LogData {
	LogType type;
	std::string message;
	float time;
};

// This module is used to manage the logs files of the game,
// it's pretty usefull to see a more detailled way of how the game has done when there is a bug.
// 
// All `Console::log` message logged but we can also add message to log without output them into the console

/** @module Logger */
namespace Logger {
	
	constexpr int __MAX_MESSAGES__ = 100; ///< Max message on in array

	LogData messages[__MAX_MESSAGES__] = {}; ///< Log messages buffers

	/*
	 * TODO: FINISH !!!
	 *
	 * Add a Log message to the log file
	 * @param LogData& - reference to the log datas we want to add
	 */
	void add(std::string& message /*, TODO: ... */);
}
