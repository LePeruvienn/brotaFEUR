#include "CurrentTime.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

/*
 * Return the actual system date
 * @return string - stringy system date
 */
std::string getCurrentTime() {
	using namespace std::chrono;

	auto now = system_clock::now();
	auto now_time_t = system_clock::to_time_t(now);
	auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

	std::tm local_tm;
#if defined(_WIN32) || defined(_WIN64)
	localtime_s(&local_tm, &now_time_t);
#else
	localtime_r(&now_time_t, &local_tm);
#endif

	std::ostringstream oss;
	oss << std::put_time(&local_tm, "%H:%M:%S")
		<< '.' << std::setfill('0') << std::setw(3) << ms.count();

	return oss.str();
}
