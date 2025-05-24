#include <string>

namespace Console {

	/*
	 * Key colors linked to the ColorsCode array
	 * The colors must be in the same order that the `colorCode` array
	 */
	enum LogColor {
		Reset,
		Gray,
		Red,
		Blue,
		Yellow,
		Green
	};


	extern const char* colorCode[]; ///< Code linked to cout colors
	extern const char* colorName[]; ///< Name of the colors

	const std::string logErrorPrefix = "❌ ERRROR: "; ///< Const prefix for log ERROR
	const std::string logWarningPrefix = "⚠️ WARNING: "; ///< Const prefix for log WARNING
	const std::string logInfoPrefix = "ℹ️ INFO: "; ///< Const prefix for log INFO
	const std::string logSuccessPrefix = "✅ SUCCESS: "; ///< Const prefix for log SUCCESS

	/*
	 * Test function used to show all the log COLORS that can be used
	 */
	void showAllColors();
 
	/*
	 * Test function used to show all the log STYLES that can be used
	 */
	void showAllStyles();

	/*
	 * Print into the console the current message in param,
	 * Can be stylized depending on the log type
	 * @param string - the message we want to show
	 * @param LogColor - show the message with a specific color, white by default
	 */
	void log(const std::string& message, const LogColor color = Reset);

	/*
	 * Print a log ERROR with a message in the console
	 * @param string - the message we want to show
	 */
	void logError (const std::string& message);

	/*
	 * Print a log WARNING with a message in the console
	 * @param string - the message we want to show
	 */
	void logWarning (const std::string& message);

	/*
	 * Print a log INFO with a message in the console
	 * @param string - the message we want to show
	 */
	void logInfo (const std::string& message);

	/*
	 * Print a log SUCCESS with a message in the console
	 * @param string - the message we want to show
	 */
	void logSuccess (const std::string& message);
}
