#include <fstream>
#include <iostream>
#include "Logger.h"
#include "Console.h"
#include "../utils/CurrentTime.h"

namespace Logger {

	// Private namespace
	namespace {

		LogData messages[__MAX_MESSAGES__] = {}; ///< Log messages buffers

		int counter = 0; ///< Next index that is free to use in buffer

		std::ofstream logFile; ///< File where we write our logs

		/*
		 * LogType to std::string function
		 * @return string
		 */
		std::string toString(const LogType& type) {
			
			std::string res;
			
			switch (type) {
				case Default:
					res = "";
					break;
				case Error:
					res = "ERROR";
					break;
				case Warning:
					res = "Warning";
					break;
				case Info:
					res = "Info";
					break;
				case Success:
					res = "SUCCESS";
					break;
			}

			return res;
		}
	}

	/*
	 * Write all the messages in buffer and reset the array
	 */
	void init() {

		// Open or create file `log.txt`
		logFile.open("log.txt", std::ios::out | std::ios::trunc);

		// If file is not open throw error
		if (!logFile.is_open())
			Console::logError("Failed to open log file");
	}

	/*
	 * Add a Log message to the log file pls fix this
	 * @param LogData& - reference to the log datas we want to add
	 */
	void add(const std::string& message, LogType type) {

		// Add new struct into the messages buffer
		messages[counter] = LogData(message, type, getCurrentTime());

		// Add one counter
		counter++;

		// If counter is at max messages, write all buffer
		if (counter == __MAX_MESSAGES__)
			flush();
	}

	/*
	 * Write all the messages in buffer and reset the array
	 */
	void flush() {

		// Write all the buffer in the log file
		for (int i = 0; i < counter; i++)
			logFile << "(" << messages[i].date << ")"
			        << "[" << toString(messages[i].type) << "] : "
			        << messages[i].message << "\n";

		// Be sure to write all text buffer in file
		logFile.flush();

		// reset counter
		counter = 0;
	}
}
