/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Ryan H
 */
#include <iostream>
#include <fstream>
#include <sstream>

#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename,
		std::string &contents) {
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {
		contents = ""; //contents string is cleared
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line;
	while (getline(file,line)) {
		contents += line;
	}

	if (file.is_open()) {
		file.close();
	}

	return SUCCESS;
}
//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,
		std::vector<std::string> &myEntryVector) {
	ofstream file;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	for (string x : myEntryVector) {
		file << x + "\n" << endl;
	}

	if(file.is_open()) {
		file.close();
	}

	return SUCCESS;
}

