#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int key, priority;
	Node *left, *right;
	Node(int x)
	{
		key = x;
		priority = rand() % 10000;
		left = right = NULL;
	}
};

class Treap
{
private:
	Node *root;

	Node * rotateLeft(Node *p)
	{
		Node *q = p->right;
		p->right = q->left;
		q->left = p;
		return q;
	}

	Node * rotateRight(Node *q)
	{
		Node *p = q->left;
		q->left = p->right;
		p->right = q;
		return p;
	}

	 Node * insert(Node *sub_tree, int key)
	 {
		// If leaf is reached
		if(sub_tree == NULL)
			return new Node(key);
		
		if(sub_tree->key < key)
		{
			// Run insert for right sub-tree
			sub_tree->right = insert(sub_tree->right, key);

			// Check if right subtree satisfies min-heap property
			if(sub_tree->right->priority < sub_tree->priority)
			{
				// Perform left rotate
				sub_tree = rotateLeft(sub_tree);
			}
		}
		else
		{
			// Run insert for left sub-tree
			sub_tree->left = insert(sub_tree->left, key);

			// Check if left subtree satisfies min-heap property
			if(sub_tree->left->priority < sub_tree->priority)
			{
				// Perform right rotate
				sub_tree = rotateRight(sub_tree);
			}
		}
		return sub_tree;
	}

	Node * deleteNode(Node *sub_tree, int key)
	{
		// Base case
		if (sub_tree == NULL) return sub_tree;
	
		// IF KEYS IS NOT AT ROOT
		if (key < sub_tree->key)
			sub_tree->left = deleteNode(sub_tree->left, key);
		else if (key > sub_tree->key)
			sub_tree->right = deleteNode(sub_tree->right, key);
	 
		// IF KEY IS AT ROOT
	 
		// If left is NULL
		else if (sub_tree->left == NULL)
		{
			Node *temp = sub_tree->right;
			delete(sub_tree);
			sub_tree = temp;  // Make right child as root
		}
	 
		// If Right is NULL
		else if (sub_tree->right == NULL)
		{
			Node *temp = sub_tree->left;
			delete(sub_tree);
			sub_tree = temp;  // Make left child as root
		}
	 
		// If key is at root and both left and right are not NULL
		else if (sub_tree->left->priority < sub_tree->right->priority)
		{
			sub_tree = rotateLeft(sub_tree);
			sub_tree->left = deleteNode(sub_tree->left, key);
		}
		else
		{
			sub_tree = rotateRight(sub_tree);
			sub_tree->right = deleteNode(sub_tree->right, key);
		}
	 
		return sub_tree;
	}
	Node * search(Node *sub_tree, int key)
	{
		if(sub_tree == NULL)
			return NULL;
		
		if(sub_tree->key == key)
			return sub_tree;
		else if(sub_tree->key < key)
		{
			return(search(sub_tree->right, key));
		}
		else return(search(sub_tree->left, key));
	}

	void inorderTraversal(Node *node)
	{
		if(node == NULL)
			return;
		inorderTraversal(node->left);
		cout << node->key << ' ';
		inorderTraversal(node->right);
	}
public:
	Treap()
	{
		root = NULL;
	}

	void insert(int x)
	{
		root = insert(root, x);
	}
	void deleteNode(int x)
	{
		root = deleteNode(root, x);
	}
	void Search(int x)
	{
		Node *temp = search(root, x);
		if(temp == NULL)
			cout << "Key not found\n";
		else
			cout << "Key found with priority " << temp->priority << '\n';
	}

	void inorderTraversal()
	{
		cout << "Inorder Traversal: ";
		inorderTraversal(root);
	}
	
};

int main()
{
	vector<int> arr = {16, 6, 22, 4, 0, 2, 1};
	Treap tree;
	for(int i = 0; i < arr.size(); i++)
		tree.insert(arr[i]);
	tree.inorderTraversal();
	cout << "\n\nSearching 16: ";
	tree.Search(16);
	cout << "Searching 0: ";
	tree.Search(0);
	cout << "Searching 3: ";
	tree.Search(3);
	cout << "\nDeleted 16, 0\n";
	tree.deleteNode(16);
	tree.deleteNode(0);
	tree.inorderTraversal();
	return 0;
}