#pragma once
#include <iostream>
#include <string>

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
		WordNode* left = NULL;
		WordNode* right = NULL;
	};
	
	WordNode* root;

	void printNode(WordNode* toPrint) const;
	bool getWordNode(WordNode* &toReturn, std::string value);
	int numHelper(WordNode* toCount);
	void deleteNode(WordNode* toDelete);
};

