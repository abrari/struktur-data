#include <iostream>

using namespace std;

struct tree_node {
    char value;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node NODE;

class binary_tree {
    public:
        NODE *root;
        binary_tree() {
            root = NULL;
        };
        void insert(char value, NODE *&inner_node) {
            NODE *newnode = new NODE;
            newnode->value = value;
            if (root == NULL) {
                root = newnode;
            }
            inner_node = newnode;
        };
        void inorder(NODE *inner_node) {
            if (inner_node) {
                inorder(inner_node->left);
                cout << inner_node->value << " ";
                inorder(inner_node->right);
            }
        };
        void print(NODE *inner_node, int level){
            if(inner_node == NULL)
                 return;

            print(inner_node->right, level+1);
            if(level != 0){
                for(int i=0; i<level-1; i++) {
                    cout << "|       ";
                }
                cout << "+-------" << inner_node->value << endl;
            } else {
                cout << inner_node->value << endl;
            }
            print(inner_node->left, level+1);
        };
};

int main() {

    binary_tree tr;
    NODE *root = tr.root;

    tr.insert('A', root);
    tr.insert('B', root->left);
    tr.insert('C', root->right);
    tr.insert('D', root->left->left);
    tr.insert('E', root->left->left->left);
    tr.insert('F', root->right->left);
    tr.insert('G', root->right->right);

    tr.print(root, 0);

    return 0;
}
