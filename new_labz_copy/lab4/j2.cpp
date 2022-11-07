// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of the tree
struct Node {
	int data;
	Node *left, *right;

	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

// Function to create a new node with
// the value val
Node* getNewNode(int val)
{
	Node* newNode = new Node(val);
	newNode->data = val;
	newNode->left = newNode->right = NULL;

	// Return the newly created node
	return newNode;
}

// Function to create the Perfect
// Binary Tree
Node* buildPerfectBT_helper(int preStart,
							int preEnd,
							int pre[])
{
	// If preStart > preEnd return NULL
	if (preStart > preEnd)
		return NULL;

	// Initialize root as pre[preStart]
	Node* root = getNewNode(pre[preStart]);
	;

	// If the only node is left,
	// then return node
	if (preStart == preEnd)
		return root;

	// Parameters for further recursion
	int leftPreStart = preStart + 1;
	int rightPreStart = leftPreStart
						+ (preEnd - leftPreStart + 1) / 2;
	int leftPreEnd = rightPreStart - 1;
	int rightPreEnd = preEnd;

	// Recursive Call to build the
	// subtree of root node
	root->left = buildPerfectBT_helper(
		leftPreStart, leftPreEnd, pre);

	root->right = buildPerfectBT_helper(
		rightPreStart, rightPreEnd, pre);

	// Return the created root
	return root;
}

// Function to build Perfect Binary Tree
Node* buildPerfectBT(int pre[], int size)
{
	return buildPerfectBT_helper(0, size - 1, pre);
}

// Function to print the Inorder of
// the given Tree
void printInorder(Node* root)
{
	// Base Case
	if (!root)
		return;

	// Left Recursive Call
	printInorder(root->left);

	// Print the data
	cout << root->data << " ";

	// Right Recursive Call
	printInorder(root->right);
}

// Driver Code
int main()
{
	int pre[] = { 1, 2, 4, 5, 3, 6, 7 };
	int N = sizeof(pre) / sizeof(pre[0]);

	// Function Call
	Node* root = buildPerfectBT(pre, N);

	// Print Inorder Traversal
	cout << "\nInorder traversal of the tree: ";
	printInorder(root);

	return 0;
}
