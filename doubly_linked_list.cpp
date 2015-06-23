#include <iostream>

using namespace std;

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

class DLL {
    NODE *head;
    NODE *tail;
    public:
        DLL() {
            head = tail = NULL;
        };
        void push_front(int newvalue) {
            NODE *newnode = new NODE;
            newnode->value = newvalue;
            if(head == NULL) {
                head = tail = newnode;
            } else {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
        };
        void push_back(int newvalue) {
            NODE *newnode = new NODE;
            newnode->value = newvalue;
            if(head == NULL) {
                head = tail = newnode;
            } else {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }
        };
        void pop_front() {
            NODE *del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        };
        void pop_back() {
            NODE *del = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete del;
        };
        void print() {
            NODE *p = head;
            while(p != tail->next) {
                cout << p->value << " - ";
                p = p->next;
            }
            cout << "NULL" << endl;
        };
        NODE* get_node_at(int index) {
            NODE *p = head;
            for(int i=0; i < index; i++) {
                p = p->next;
            }
            return p;
        };
        void insert_after(NODE *p, int newvalue) {
            NODE *newnode = new NODE;
            newnode->value = newvalue;

            newnode->next = p->next;
            newnode->prev = p;
            p->next = newnode;
            newnode->next->prev = newnode;
        };
};

int main() {


    return 0;
}




