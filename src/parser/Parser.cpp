#include "Parser.h"

#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

/** @module Parser */
namespace Parser {


	/* Private namespace 🥷 */
	namespace {

		/*
		 * Get all the files paths
		 * @param directoryPath - the directoryPath wher we load all the files
		 */
		std::vector<fs::path> getFilesFromDirectory (const std::string& directoryPath) {
		
			// Scene files array
			std::vector<fs::path> sceneFiles;

			// For all files in directory
			for (const fs::directory_entry& entry : fs::directory_iterator(directoryPath))
				// If file have for extension `.scene`, add it to the sceneFiles array
				if (entry.is_regular_file() && entry.path().extension() == ".scene")
					sceneFiles.push_back(entry.path());

			return sceneFiles;
		}
	}

	/*
	 * Load all the file from a directory
	 * @param directoryPath - the directoryPath wher we load all the files
	 */
	void loadFilesFrom(const std::string& directoryPath) {

	}

	/*
	 * Load the file in param
	 * @param filePath - path of the file we want to laod
	 */
	void loadFile(const std::string& filePath) {

	}
}
