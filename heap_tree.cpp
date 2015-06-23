#include <iostream>

using namespace std;

// DRAW TREE ==========================================

#include <vector>
#include <math.h>

template<class T>
class heap_tree_printer {
	private:
		vector<T> value;
		int left(int i) {
			return (i*2 + 1);
		};
		int right(int i) {
			return (i*2 + 2);
		};
		void printWhitespaces(int count) {
			for (int i = 0; i < count; i++) cout << " ";
		};
		void printNodeInternal(vector<int> nodes, int level, int maxLevel) {
			if (nodes.empty()) return;

			int floor = maxLevel - level;
			int endgeLines = (int) pow(2, (max(floor - 1, 0)));
			int firstSpaces = (int) pow(2, (floor)) - 1;
			int betweenSpaces = (int) pow(2, (floor + 1)) - 1;

			printWhitespaces(firstSpaces);

			vector<int> newNodes;
			for (vector<int>::iterator node = nodes.begin(); node != nodes.end(); node++) {
				if (*node >= value.size()) break;

				cout << value[*node];
				if (left(*node)  < value.size()) newNodes.push_back(left(*node));
				if (right(*node) < value.size()) newNodes.push_back(right(*node));

				printWhitespaces(betweenSpaces);
			}
			cout << endl;

			for (int i = 1; i <= endgeLines; i++) {
				for (unsigned int j = 0; j < nodes.size(); j++) {
					printWhitespaces(firstSpaces - i);
				
					if (left(nodes[j]) < value.size()) cout << "/";
					else cout << " ";

					printWhitespaces(i + i - 1);

					if (right(nodes[j]) < value.size()) cout << "\\";
					else cout << " ";

					printWhitespaces(endgeLines + endgeLines - i);
				}
				cout << endl;
			}
			printNodeInternal(newNodes, level + 1, maxLevel);
		};
	public:
		void printTree(vector<T> treevalue) {
			value = treevalue;

			int maxLevel = (int) (log(value.size()) / log(2));
			int max = maxLevel + 1;
			vector<int> root;
			root.push_back(0);
			printNodeInternal(root, 0, max);
		};
};

// DRAW TREE ==========================================

class Heaptree {
	private:
		vector<float> value;
		std::vector<float>::iterator it;
	public:
		Heaptree() {};
		void konstruksiCBT(float *,int);
		void konstruksiHeap();
		void maxHeap(int);
		int parent(int);
		int left(int);
		int right(int);
		void tukar(float*,float*);
		void showHeaptree();
		void preOrder(int);
		vector<float> getValue() {return value;};

		float ambilRoot() {
			float nilaiRoot = value.front();    
			float nilaiTerakhir = value.back(); // dari STL vector

			value[0] = nilaiTerakhir; // nilai root diganti dengan yg terakhir
			value.pop_back();         // hapus nilai terakhir

			// re-heapify
			maxHeap(0);

			return nilaiRoot;
		};
};

void Heaptree::konstruksiCBT(float *A,int k)
{
	value.insert (value.begin(), A, A+k);
}

void Heaptree::showHeaptree()
{
	it=value.begin();
	for (it=value.begin(); it<value.end(); it++)
		cout << ' ' << *it;
	cout<<'\n';
}

void Heaptree::konstruksiHeap()
{
	int first,i;
	first=parent(value.size()-1);
	for(i=first; i>=0; i--) {
		maxHeap(i);
	}
}

void Heaptree::maxHeap(int i)
{
	int q,k,largest;
	q=left(i);
	k=right(i);
	if(q < value.size() && value[q]>value[i]) largest=q;
	else largest=i;
	if(k < value.size() && value[k]>value[largest]) largest=k;
	if(largest!=i) {
		tukar(&value[i],&value[largest]);
		maxHeap(largest);
	}
}

void Heaptree::tukar(float *a,float *b)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int Heaptree::parent(int i)
{
	return ((i-1)/2);
}

int Heaptree::left(int i)
{
	return (i*2 + 1);
}

int Heaptree::right(int i)
{
	return (i*2 + 2);
}

void Heaptree::preOrder(int i)
{
	if(i<value.size()) {
		cout<<value[i]<<' ';
		preOrder(left(i));
		preOrder(right(i));
	}
}

int main()
{
	Heaptree T;
	float DATA[]= {3,1,2,6,7,10,4,15,9,8};
	int N=10;

	heap_tree_printer<float> P;

	T.konstruksiCBT(DATA,N);
	P.printTree(T.getValue());

	T.konstruksiHeap();
	cout << "HEAPIFY\n========================\n";
	P.printTree(T.getValue());

	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;
	cout << "ROOT = " << T.ambilRoot() << endl;

	return 0;
}

/* DEPARTEMEN ILMU KOMPUTER IPB: 21 Agustus 2014 */


