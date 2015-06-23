#include <iostream>

using namespace std;

struct tree_node {
	int data;
	tree_node *left;
	tree_node *right;
};

// <========================

// Binary tree diagram generator. Works by magic.
// Modified from Java version at http://stackoverflow.com/a/4973083/1198623

#include <math.h>
#include <vector>

template<class T>
class binary_tree_printer {
private:
	void printWhitespaces(int count) {
		for (int i = 0; i < count; i++) cout << " ";
	};
	int maxLevel(tree_node *node) {
		if (node == NULL) return 0;
		return max(maxLevel(node->left), maxLevel(node->right)) + 1;
	};
	bool isAllElementsNull(vector<tree_node*> list) {
		for (vector<tree_node*>::iterator object = list.begin(); object != list.end(); object++) {
			if (*object != NULL)
				return false;
		}

		return true;
	};
	void printNodeInternal(vector<tree_node*> nodes, int level, int maxLevel) {
		if (nodes.empty() || isAllElementsNull(nodes))
			return;

		int floor = maxLevel - level;
		int endgeLines = (int) pow(2, (max(floor - 1, 0)));
		int firstSpaces = (int) pow(2, (floor)) - 1;
		int betweenSpaces = (int) pow(2, (floor + 1)) - 1;

		printWhitespaces(firstSpaces);

		vector<tree_node*> newNodes;
		for (vector<tree_node*>::iterator node = nodes.begin(); node != nodes.end(); node++) {
			if (*node != NULL) {
				cout << (*node)->data;
				newNodes.push_back((*node)->left);
				newNodes.push_back((*node)->right);
			} else {
				newNodes.push_back(NULL);
				newNodes.push_back(NULL);
				cout << " ";
			}

			printWhitespaces(betweenSpaces);
		}
		cout << endl;

		for (int i = 1; i <= endgeLines; i++) {
			for (unsigned int j = 0; j < nodes.size(); j++) {
				printWhitespaces(firstSpaces - i);
				if (nodes.at(j) == NULL) {
					printWhitespaces(endgeLines + endgeLines + i + 1);
					continue;
				}

				if (nodes.at(j)->left != NULL)
					cout << "/";
				else
					printWhitespaces(1);

				printWhitespaces(i + i - 1);

				if (nodes.at(j)->right != NULL)
					cout << "\\";
				else
					printWhitespaces(1);

				printWhitespaces(endgeLines + endgeLines - i);
			}

			cout << endl;
		}

		printNodeInternal(newNodes, level + 1, maxLevel);
	};
public:
	void printTree(tree_node *root) {
		int max = maxLevel(root);

		vector<tree_node*> troot;
		troot.push_back(root);

		printNodeInternal(troot, 0, max);
	};
};

// <========================

class binary_tree {
public:
	tree_node *root;
	binary_tree() {
		root = NULL;
	};
	void insert(int d)
	{
		tree_node* t = new tree_node;
		tree_node* parent;
		t->data = d;
		t->left = NULL;
		t->right = NULL;
		parent = NULL;
		// is this a new tree?

		if (root == NULL) root = t;
		else
		{
			// Note: ALL insertions are as leaf nodes
			tree_node* curr;
			curr = root;
			// Find the Node's parent
			while(curr)
			{
				parent = curr;
				if(t->data > curr->data) curr = curr->right;
				else curr = curr->left;
			}

			if(t->data < parent->data)
				parent->left = t;
			else
				parent->right = t;
		}
	};

	bool search(int value) {
		tree_node *target;
		target = root;

		while (target != NULL) {
			// Kalau langsung ketemu
			if (target->data == value) {
				return true;
			} else {
				if (value < target->data) {
					// Kurang dari, cari ke kiri
					target = target->left;
				} else {
					// Lebih dari, cari ke kanan
					target = target->right;
				}			
			}
		}

		return false;
	};

	void preorder(tree_node *node) {
		if (node != NULL) {
			// root
			cout << node->data << " ";
			// kiri
			preorder(node->left);
			// kanan
			preorder(node->right);
		}
	};
	void inorder(tree_node *node) {
		if (node != NULL) {
			// kiri
			inorder(node->left);
			// root
			cout << node->data << " ";
			// kanan
			inorder(node->right);
		}
	};
	void postorder(tree_node *node) {
		if (node != NULL) {
			// kiri
			postorder(node->left);
			// kanan
			postorder(node->right);
			// root
			cout << node->data << " ";
		}
	};
};

int main() {
	binary_tree T;

	T.insert(5);
	T.insert(3);
	T.insert(1);
	T.insert(4);
	T.insert(6);
	T.insert(2);
	T.insert(3);
	T.insert(8);

	binary_tree_printer<int> P;

	P.printTree(T.root);

	T.inorder(T.root);

	if (T.search(4) == true) cout << "Nilai ada" << endl;
	else cout << "Nilai tidak ada" << endl;

	return 0;
}