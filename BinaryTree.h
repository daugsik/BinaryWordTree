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
		void printWordNode();		
		void deleteWordNode();		//recursive method to delete nodes
	};
	
	WordNode* root;

	WordNode* getWordNode(std::string nodeWord);
};

