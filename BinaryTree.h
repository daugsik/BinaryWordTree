#pragma once
template<typename T>
class BinaryTree
{
public:
	BinaryTree(void);
	~BinaryTree(void);

	Node* getNode(T value);
	bool insertNode(T value);


private:
	struct Node
	{
		T nodeVal;
		int count;
		Node* leftBranch;
		Node* rightBranch;
	};

	Node* root;

};

