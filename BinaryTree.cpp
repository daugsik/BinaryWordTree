#include "BinaryTree.h"


BinaryTree::BinaryTree(void)
{
	root = new WordNode;
	root->count = 0;
	root->word = "";
};


BinaryTree::~BinaryTree(void)
{

};

/*
	Assumes a properly formatted (all lower-case and no whitespace)
	If the word to be added exists, increment the associated WordNode
	count value. If not, create a new node and increment counter by 1.
*/
void BinaryTree::Add(std::string toAdd)
{
	WordNode *nodeP = root;
	
	// If the word already exists in the tree, increment the counter in the node
	// and exit.
	if (getWordNode(nodeP, toAdd))
	{
		nodeP->count++;
		return;
	}

	// Else, create a new node and attach to the tree.
	// Note: as a result of getWordNode, nodeP points to the closest leaf node 
	//		 to the word to be added

	WordNode *temp;
	temp = new WordNode;
	temp->count = 1;
	temp->word = toAdd;

	// left branch add
	if (toAdd < nodeP->word) { nodeP->left = temp; }
	// equal case is taken care of, so right branch case written as else
	else { nodeP->right = temp; };

	temp = NULL;
	nodeP = NULL;
	return;
};

int BinaryTree::numWords()
{
	return numHelper(root);
};

int BinaryTree::numHelper(WordNode* toCount)
{
	//If the root is "empty," don't count
	if (toCount->count <= 0)	{	return 0;	};

	int counter = 1;

	if (toCount->left != NULL) { counter += numHelper(toCount->left); };
	if (toCount->right != NULL) { counter += numHelper(toCount->left); };

	return counter;
};

void BinaryTree::printWord(WordNode& toPrint)
{

};

bool BinaryTree::getWordNode(WordNode* toReturn, std::string value)
{
	// FOUND CASE
	if (value == toReturn->word)
	{
		return true;
	};
	
	// LEFT BRANCH
	if (toReturn->left != NULL && value < toReturn->word)
	{
		return getWordNode(toReturn->left, value);
	};

	// RIGHT BRANCH
	if (toReturn->right != NULL && value > toReturn->word)
	{
		return getWordNode(toReturn->left, value);
	};

	// IF NOT FOUND RETURN FALSE
	return false;
};

std::ostream& operator<<(std::ostream& os, const BinaryTree& toPrint)
{
	return os;
};