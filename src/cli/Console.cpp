#include <iostream>
#include "Console.h"

namespace Console {

	const char* colorCode[] = { ///< Code linked to cout colors
 		"\033[0m",  // Reset
		"\033[37m", // Gray
		"\033[31m", // Red
		"\033[34m", // Blue
		"\033[33m", // Yellow
		"\033[32m"  // Green
	};

	const char* colorName[] = { ///< Name of the colors
 		"Reset",  // Reset
		"Gray",   // Gray
		"Red",    // Red
		"Blue",   // Blue
		"Yellow", // Yellow
		"Green"   // Green
	};

	/*
	 * Test function used to show all the log COLORS that can be used
	 */
	void showAllColors() {

		// Get the last index of the enum
		const int last = Green + 1;

		std::string message;
		
		// Show Log all the colors
		for (int i = 0; i < last; i++)
			log (colorName[i], static_cast<LogColor>(i));
	}

	/*
	 * Test function used to show all the log STYLES that can be used
	 */
	void showAllStyles() {

		// Show out all the differents log messsages
		log ("This is a default log message");
		logError ("OH NOW THIS IS AN ERRROR LOG MESSSAGE");
		logWarning ("Carefull with the Warning messsages !");
		logInfo ("Did you know that you can do `logInfo` messsages ?");
		logSuccess ("All the log tests has been run");
	}

	/*
	 * Print into the console the current message in param,
	 * Can be stylized depending on the log type
	 * @param string - the message we want to show
	 * @param LogStyle - optional, is `Default` by default
	 */
	void log(const std::string& message, const LogColor color) {

		// Print the message in param
		std::cout << colorCode[color]<< message << colorCode[Reset] << std::endl;
	}

	/*
	 * Print a log ERROR with a message in the console
	 * @param string - the message we want to show
	 */
	void logError (const std::string& message) {
		// Show message with prefix & style
		std::cout << colorCode[Red] << logErrorPrefix << message << colorCode[Reset] << std::endl;
	}

	/*
	 * Print a log WARNING with a message in the console
	 * @param string - the message we want to show
	 */
	void logWarning (const std::string& message) {
		// Show message with prefix & style
		std::cout << colorCode[Yellow] << logWarningPrefix << message << colorCode[Reset] << std::endl;
	}

	/*
	 * Print a log INFO with a message in the console
	 * @param string - the message we want to show
	 */
	void logInfo (const std::string& message) {
		// Show message with prefix & style
		std::cout << colorCode[Blue] << logInfoPrefix << message << colorCode[Reset] << std::endl;
	}

	/*
	 * Print a log SUCCESS with a message in the console
	 * @param string - the message we want to show
	 */
	void logSuccess (const std::string& message) {
		// Show message with prefix & style
		std::cout << colorCode[Green] << logSuccessPrefix << message << colorCode[Reset] << std::endl;
	}
}
