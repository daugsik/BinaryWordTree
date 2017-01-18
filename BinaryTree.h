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
	struct Node
	{
		std::string word;
		int count;
		Node* leftBranch;
		Node* rightBranch;
		void printNode();		
		void deleteNode();		//recursive method to delete nodes
	};
	
	Node* root;

	Node* getNode(std::string nodeWord);
};

