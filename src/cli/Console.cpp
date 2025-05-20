#include <iostream>
#include "Console.h"

namespace Console {

	/*
	 * Print into the console the current message in param,
	 * Can be stylized depending on the log type
	 * @param string - the message we want to show
	 */
	void log(const std::string& message) {

		// Print the message in param
		std::cout << message << std::endl;
	}
}
