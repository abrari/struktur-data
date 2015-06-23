#include <iostream>
#include <stdlib.h>

using namespace std;

struct tree_node {
	char data;
	int height;
	struct tree_node *left;
	struct tree_node *right;
};

// fungsi tambahan untuk menggambar tree
struct trunk {
	struct trunk *prev;
	string str;
};
 
void show_trunks(struct trunk *p)
{
	if (!p) return;
	show_trunks(p->prev);
	cout << p->str;
}
 
// magic
void show_tree(struct tree_node *root, struct trunk *prev, int is_left)
{
	if (root == NULL) return;
	if (prev == NULL && is_left == 0) cout << "TREE:\n";
 
	struct trunk this_disp = { prev, "    " };
	string prev_str = this_disp.str;
	show_tree(root->right, &this_disp, 1);
 
	if (!prev)
		this_disp.str = "---";
	else if (is_left) {
		this_disp.str = ".--";
		prev_str = "   |";
	} else {
		this_disp.str = "`--";
		prev->str = prev_str;
	}
 
	show_trunks(&this_disp);
	cout << root->data << "\n";
 
	if (prev) prev->str = prev_str;
	this_disp.str = "   |";
 
	show_tree(root->left, &this_disp, 0);
	if (!prev) cout << "";
}

class binary_tree {
public:
	tree_node *root;
	binary_tree() {
		root = NULL;
	};

	void insert(char value, tree_node *&node)
	{
		tree_node *node_root = node;
			 
		if (node_root == NULL) {
			tree_node *newnode = new tree_node;
			newnode->data = value;
			newnode->height = 1;
			newnode->left = NULL;
			newnode->right = NULL;			
			
			node = newnode;
		
		} else if (value != node_root->data) {
			
			if (value < node_root->data) {
				insert(value, node_root->left);
			} else {
				insert(value, node_root->right);
			}
			adjust_balance(node);
			
		}		
	}

	int get_balance(tree_node *n) {
		if(n == NULL) return 0;
		
		int left = 0, right = 0;
		if(n->left != NULL) left = n->left->height;
		if(n->right != NULL) right = n->right->height;
		
		return left - right;
	}

	void set_height(tree_node *n) {
		int left = 0, right = 0;
		if(n->left != NULL) left = n->left->height;
		if(n->right != NULL) right = n->right->height;		
		
		n->height = 1 + max(left, right);
	}

	void adjust_balance(tree_node *&node)
	{
		tree_node *nroot = node;
		int balance = get_balance(nroot);
		
		if(balance == 2) {
			if(get_balance(nroot->left) < 0) {
				nroot->left = rotate_left(nroot->left);
			}
			nroot = rotate_right(node);
		} else if(balance == -2) {
			if(get_balance(nroot->right) < 0) {
				nroot->right = rotate_right(nroot->right);
			}
			nroot = rotate_left(node);
		}
		 
		if (nroot != NULL) set_height(nroot);
		
		node = nroot;
	}

	tree_node *rotate_left(tree_node *&node)
	{
		if (node->right == NULL)
			return node;
		
		cout << "ROTATE LEFT at " << node->data << endl; 
		
		tree_node *old_root = node;
		tree_node *new_root = old_root->right;
	 
		old_root->right = new_root->left;
		set_height(old_root);
		new_root->left = old_root;
		
		return new_root;
	}

	tree_node *rotate_right(tree_node *&node)
	{
		if (node->left == NULL)
			return node;

		cout << "ROTATE RIGHT at " << node->data << endl; 

		tree_node *old_root = node;
		tree_node *new_root = old_root->left;
	 
		old_root->left = new_root->right;
		set_height(old_root);
		new_root->right = old_root;
		
		return new_root;
	}

};

int main(int argc, char **argv)
{
	binary_tree T;
	
	T.insert('4', T.root);
	T.insert('2', T.root);
	T.insert('3', T.root);
	
	// show_tree(T.root, 0, 0);
	
	return 0;
}

