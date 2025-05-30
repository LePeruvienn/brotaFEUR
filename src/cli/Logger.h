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
	std::string message;
	LogType type;
	std::string date;
	/* Default Constructor */
	LogData() : message(""), type(Default), date("") {}
	/* Constructor */
	LogData(const std::string& msg, LogType t, const std::string& d)
		: message(msg), type(t), date(d) {}
};

// This module is used to manage the logs files of the game,
// it's pretty usefull to see a more detailled way of how the game has done when there is a bug.
// 
// All `Console::log` message logged but we can also add message to log without output them into the console

/** @module Logger */
namespace Logger {
	
	// Include __MAX_MESSAGES__ once, old method to be sure to work on older compilers
	#ifndef LOGGER_MAX_MESSSAGES_H
	#define LOGGER_MAX_MESSSAGES_H

	constexpr int __MAX_MESSAGES__ = 10; ///< Max message on in array

	#endif // LOGGER_MAX_MESSSAGES_H

	/*
	 * Write all the messages in buffer and reset the array
	 */
	void init();

	/*
	 * Add a Log message to the log file
	 * @param LogData& - reference to the log datas we want to add
	 */
	void add(const std::string& message, LogType type);

	/*
	 * Write all the messages in buffer and reset the array
	 */
	void flush();
}
