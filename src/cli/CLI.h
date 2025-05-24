#include <atomic>
#include <string>

/** @module CLI */
namespace CLI {

	extern std::atomic<bool> running; ///< Is the CLI thread running

	/*
	 * CLI main thread function
	 */
	void run();

	/*
	 * Exit CLI loop
	 */
	void exit();
}
