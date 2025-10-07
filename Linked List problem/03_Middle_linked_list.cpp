#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;
public:
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

    void printLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void middleNode() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        // if (count == 0) {
        //     cout << "List is empty" << endl;
        //     return; 
        // }
        int middle = (count / 2) + 1; 
        temp = head;
        for (int i = 1; i < middle; i++) {
            temp = temp->next;
        }

        cout << "Middle Node: " << temp->data << endl;
    }

    // Floyd’s two-pointer technique
    void slowFastPointer(){
        Node* slow =head;
        Node* fast =head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout << "Middle Node (slowFastPointer):" << slow->data << endl;
    }
};

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    cout<< endl;
    cout << "Original List: ";
    ll.printLL();
    ll.middleNode();
    ll.slowFastPointer();

    return 0;
}
