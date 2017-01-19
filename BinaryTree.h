#pragma once
#include <iostream>


class BinaryTree
{
public:
	BinaryTree(void);
	~BinaryTree(void);

	void Add(std::string value);
	int numWords();
	friend std::ostream& operator<<(std::ostream& os, const BinaryTree& toPrint);


private:
	struct WordNode
	{
		std::string word;
		int count;
		WordNode* left;
		WordNode* right;
	};
	
	WordNode* root;

	void printNode(WordNode& toPrint);
	bool getWordNode(WordNode* &toReturn, std::string value);
	int numHelper(WordNode* toCount);
	void deleteNode(WordNode* toDelete);
};

