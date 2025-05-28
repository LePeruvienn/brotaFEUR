#include <string>
#include <fstream>
#include <iostream>

// This module is used to create save file with all the datas that the game need to run
// This way we can easly configure all the game items, characters, mobs easly

/** @module Parser */
namespace Parser {

	/*
	 * Load all the file from a directory
	 * @param directoryPath - the directoryPath wher we load all the files
	 */
	void loadFilesFrom(const std::string& directoryPath);

	/*
	 * Load the file in param
	 * @param filePath - path of the file we want to laod
	 */
	void loadFile(const std::string& filePath);
}
