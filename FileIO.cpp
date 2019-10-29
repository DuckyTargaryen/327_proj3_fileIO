/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

/**
 * Gets the contents from a file.
 * @param filename - The name of the file being read
 * @param contents - Contains the contents of the file
 * @return int - Represents whether or not the file was successfully read
 */
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream inputFile;
	inputFile.open(filename.c_str());
	if(!inputFile.is_open()){
		contents = "";
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	string input;
	while(!inputFile.eof()){
		getline(inputFile, input, '\n');
		contents += input;
	}
	inputFile.close();
	return SUCCESS;
}

/**
 * Writes the contents of myEntryVector to a file.
 * @param filename - The file being writen to
 * @param myEntryVector - The vector containing the contents
 * @return int - Represents whether or not the file was successfully written to
 */
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream outputFile;
	outputFile.open(filename.c_str());
	if(!outputFile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	int length = myEntryVector.size();
	for(int i = 0; i < length; i++){
		outputFile << myEntryVector[i] << endl;
	}
	outputFile.close();
	return SUCCESS;
}


