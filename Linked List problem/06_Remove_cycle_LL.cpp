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
        int count = 0; // to avoid infinite loop if cycle exists
        while (temp != NULL && count < 20) {
            cout << temp->data << "->";
            temp = temp->next;
            count++;
        }
        cout << "NULL" << endl;
    }

    Node* slowFastPointer() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // start of cycle
            }
        }
        return NULL; // no cycle
    }

    void RemoveCycle() {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle) {
            return; // no cycle
        }

        slow = head;
        Node* prev = NULL;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // break cycle
    }

    // simple function to create cycle
    void createCycle(int pos) {
        Node* temp = head;
        Node* cycleNode = NULL;
        int count = 1;

        while (temp->next != NULL) {
            if (count == pos) cycleNode = temp;
            temp = temp->next;
            count++;
        }
        if (cycleNode != NULL)
            temp->next = cycleNode; // last node points back to pos-th node
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

    // create cycle: last node points back to node 3
    ll.createCycle(3);

    if (ll.slowFastPointer() != NULL)
        cout << "Cycle detected at node with value: " << ll.slowFastPointer()->data << endl;
    else
        cout << "No cycle found." << endl;

    ll.RemoveCycle();

    if (ll.slowFastPointer() == NULL)
        cout << "Cycle removed successfully!" << endl;

    cout << "List after removing cycle: ";
    ll.printLL();

    return 0;
}
