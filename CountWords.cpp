//
//
//
//

#include <string>
#include "BinaryTree.h"
#include <fstream>

int main (int argc, char* argv[])
{
	std::string line;

	std::string fileName("TestInput.txt"); //REPLACE THIS THAHGALGHALGHALGHALGHALHGLGHALGHLAGHLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLAHGLHALGHA
	std::cout << "Reading in: " << fileName << std::endl;		//echo input

	std::ifstream book;
	book.open(fileName);										//opens input

	while( std::getline( book, line ) )
	{
			std::cout << line << std::endl;
	};



	return 0;
}