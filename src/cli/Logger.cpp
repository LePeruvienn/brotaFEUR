#include "Logger.h"

namespace Logger {

	// Private namespace
	namespace {

		LogData messages[__MAX_MESSAGES__] = {}; ///< Log messages buffers

		int counter = 0; ///< Next index that is free to use in buffer

		/*
		 * Write all the messages in buffer and reset the array
		 */
		void flush() {
	
		}

		/*
		 * LogType to std::string function
		 * @return string
		 */
		std::string toString(const LogType& type) {
			
			std::string res;
			
			switch (type) {
				case Default:
					res = "";
				case Error:
					res = "ERROR";
				case Warning:
					res = "Warning";
				case Info:
					res = "Info";
				case Success:
					res = "SUCCESS";
			}

			return res;
		}
	}

	/*
	 * Add a Log message to the log file
	 * @param LogData& - reference to the log datas we want to add
	 */
	void add(const std::string& message, LogType type, float time) {

	}
}
