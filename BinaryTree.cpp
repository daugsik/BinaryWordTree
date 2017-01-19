#include "BinaryTree.h"


BinaryTree::BinaryTree(void)
{
	root = new WordNode;
	root-> count = 0;
	root-> word = "";
};


BinaryTree::~BinaryTree(void)
{
	std::cout << ".";
	deleteNode(root);
};

/* Helper function for ~BinaryTree
	traverses down left first, then right, then deallocates
	node memory before deleting pointers pointers.
*/
void BinaryTree::deleteNode(WordNode* toDelete)
{
	if (toDelete->left != NULL)
	{
		deleteNode(toDelete->left);
	}

	if (toDelete->right != NULL)
	{
		deleteNode(toDelete->right);
	}

	toDelete->left = NULL;
	toDelete->right = NULL;
	delete toDelete;
	toDelete = NULL;
};

/*
	Assumes a properly formatted (all lower-case and no whitespace)
	If the word to be added exists, increment the associated WordNode
	count value. If not, create a new node and increment counter by 1.

	Special Case: If the tree is currently empty (represented by a root
	node counter of 0) input the first string seen into the root node.
*/
void BinaryTree::Add(std::string toAdd)
{
	// If the tree is empty, fill the root.
	if (root->count == 0)
	{
		root->word = toAdd;
		root->count = 1;
	};

	WordNode *nodeP = root;
	
	// If the word already exists in the tree, increment the counter in the node
	// and exit.
	if (getWordNode(nodeP, toAdd))
	{
		nodeP->count++;
		return;
	};

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

void BinaryTree::printNode(WordNode* toPrint) const
{
	if (toPrint->left != NULL)
	{
		printNode(toPrint->left);
	}

	if (toPrint->right != NULL)
	{
		printNode(toPrint->right);
	}

	std::cout << toPrint->word << " " << toPrint->count << std::endl;
};

/*
	Searches the tree for a specific word
		If the word is found, it returns true.
		If not, it returns false.
	As a side effect of how the toReturn pointer is manipulated, after
	the function finishes, the calling toReturn points at the last node
	traversed.
*/
bool BinaryTree::getWordNode(WordNode* &toReturn, std::string value)
{
	// FOUND CASE
	if (value == toReturn->word)
	{
		return true;
	};
	
	// LEFT BRANCH
	if (toReturn->left != NULL && value < toReturn->word)
	{
		toReturn = toReturn->left;
		return getWordNode(toReturn, value);
	};

	// RIGHT BRANCH
	if (toReturn->right != NULL && value > toReturn->word)
	{
		toReturn = toReturn->right;
		return getWordNode(toReturn, value);
	};

	// IF NOT FOUND RETURN FALSE
	return false;
};

std::ostream& operator<<(std::ostream& os, const BinaryTree& toPrint)
{
	toPrint.printNode(toPrint.root);
	return os;
};