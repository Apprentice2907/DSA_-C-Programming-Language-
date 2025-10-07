#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(Node* h) {
        while (h != NULL) {
            cout << h->val << " ";
            h = h->next;
        }
        cout << endl;
    }

    Node* mergeTwoLists(Node* h1, Node* h2) {
        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;
        if (h1->val <= h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }
    }
};

int main() {
    List l1, l2, result;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    Node* mergedHead = result.mergeTwoLists(l1.head, l2.head);
    result.printList(mergedHead);
    return 0;
}
