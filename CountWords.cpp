//
//
//
//

#include <string>
#include "BinaryTree.h"
#include <fstream>
#include <iostream>

void iterateFile (int& head, int& tail, std::ifstream& toRead, BinaryTree tree);
void formatCases (std::string& toChange);

int main (int argc, char* argv[])
{
	std::string line;
	BinaryTree wordTree;

	std::string fileName("TestInput.txt"); //REPLACE THIS THAHGALGHALGHALGHALGHALHGLGHALGHLAGHLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLHALGHA
	std::cout << "Reading in: " << fileName << std::endl;		//echo input

	std::ifstream book;
	book.open(fileName);										//opens input

	int wordHead = 0;
	int wordLength = 1;

	do { iterateFile(wordHead, wordLength, book, wordTree); }
	while (book);													//while there are still words in the file, continue iterating

	//std::cout << wordTree;											//Print contents of the tree

	return 0;
}

/*
	Workhorse function. Takes in and writes on outside variables to iterate and obtain words. 
*/
void iterateFile(int& head, int& length, std::ifstream& toRead, BinaryTree tree)
{
	
}

/*
	Takes in string and replaces with all lower-case equivalent.
*/
void formatCases(std::string& toChange)
{
	toChange = "HAHAHA ";
}