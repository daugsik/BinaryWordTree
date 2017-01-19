//
//
//
//

#include <string>
#include "BinaryTree.h"
#include <fstream>
#include <iostream>

void iterateLine(std::string lineToRead, BinaryTree& tree);
void formatCases (std::string& toChange);
char loweredCase(const char& val);
bool rangeCheck(const int& location, const std::string& lineToRead);

int main (int argc, char* argv[])
{
	BinaryTree wordTree;

	std::string fileName("TestInput.txt"); //REPLACE THIS THAHGALGHALGHALGHALGHALHGLGHALGHLAGHLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLHALGHA
	std::cout << "Reading in: " << fileName << std::endl;		//echo input

	std::ifstream book;
	book.open(fileName);										//opens input

	long int wordHead = 0;
	std::string lineToRead = "";

	while (getline(book, lineToRead))
	{
		iterateLine(lineToRead, wordTree);						//while there are still words in the file, continue iterating
		std::cout << ".";
	}

	std::cout << std::endl;

	std::ofstream output;
	output.open("output.txt");
	output << wordTree;										//Print contents of the tree to external file

	std::cout << "Word Tree Completed. Total unique word count: " << wordTree.numWords() << std::endl;

	return 0;
}

/*
	Workhorse function. 
*/
void iterateLine(std::string lineToRead, BinaryTree& tree)
{
	long unsigned int head = 0;

	//do until head reaches the end of the line
	while (head < lineToRead.length() - 1 && lineToRead.length() != 0)
	{
		int unsigned length = 0;
		std::string temp = "";

		// removes leading whitespace and non-alphanumeric characters
		while (!rangeCheck(head,lineToRead)
			&& head < lineToRead.length())		// and there is still some string to read
		{
			head++;									// iterate head forward
			if (head >= lineToRead.length()) { return; };
		};

		while ((head + length < lineToRead.length())	// if the substring is not longer than the string
				&& (rangeCheck(head+length, lineToRead)
				|| lineToRead.at(head + length) == '\''))			// or an apostrophe, increment length
		{
			length++;
		}

		temp = lineToRead.substr(head, length);
		formatCases(temp);

		tree.Add(temp);

		head += length;
	}
}

bool rangeCheck(const int& location, const std::string& lineToRead)
{
	return (
		(lineToRead.at(location) >= 'A' && lineToRead.at(location) <= 'Z') // and is either an alphanumeric character
		|| (lineToRead.at(location) >= 'a' && lineToRead.at(location) <= 'z'));
}

/*
	Takes in string and replaces with all lower-case equivalent.
*/
void formatCases(std::string& toChange)
{
	std::string lowCase = "";
	for (unsigned int i = 0; i < toChange.size(); i++)
	{
		lowCase.append(1, tolower(toChange.at(i)));
	}

	toChange = lowCase;
}
