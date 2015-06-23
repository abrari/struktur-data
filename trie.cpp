#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
	public:
	char character;
	bool ending;
	vector<TrieNode*> children;
	
	TrieNode* findChild(char c) {
		for (unsigned int i = 0; i < children.size(); i++)
		{
			TrieNode* tmp = children.at(i);
			if (tmp->character == c)
				return tmp;
		}
		return NULL;			
	}
};

class Trie 
{
	public:
	TrieNode* root;
	
	Trie() {
		root = new TrieNode();
	}
	void insert(string s) {
		TrieNode* current = root;
		int len = s.length();
		
		if (len == 0) {
			current->ending = true;
			return;
		}
		
		for (int i = 0; i < len; i++)
		{        
			TrieNode* child = current->findChild(s[i]);
			if (child != NULL)
			{
				current = child;
			}
			else
			{
				TrieNode* tmp = new TrieNode();
				tmp->character = s[i];
				current->children.push_back(tmp);
				current = tmp;
			}
			if (i == len - 1)
				current->ending = true;
		}		
	}
	bool search(string s) {
		TrieNode* current = root;
		int len = s.length();

		while (current != NULL)
		{
			for (int i = 0; i < len; i++)
			{
				TrieNode* tmp = current->findChild(s[i]);
				if (tmp == NULL)
					return false;
				else
					current = tmp;
			}

			if (current->ending == true)
				return true;
			else
				return false;
		}

		return false;		
	}
	void traverse(string prefix, TrieNode *n) {
		prefix += n->character;

		if (n->ending == true)
			cout << prefix << endl;

		for (unsigned int i = 0; i < n->children.size(); i++) {
			TrieNode *ch = n->children.at(i);
			traverse(prefix, ch);
		}
	}
	void traverseAll() {
		traverse("", root);
	}
	void traversePrefix(string prefix) {
		TrieNode* current = root;
		int len = prefix.length();
		
		for (int i = 0; i < len; i++)
		{
			TrieNode* tmp = current->findChild(prefix[i]);
			if (tmp == NULL) return;
			current = tmp;
		}
		
		traverse(prefix, current);
		
	}
};

int main(int argc, char **argv)
{
	Trie* t = new Trie;
	
	t->insert("hello");
	t->insert("helly");
	t->insert("test");
	t->insert("hai");
	
	t->traversePrefix("hely");
	
	return 0;
}

