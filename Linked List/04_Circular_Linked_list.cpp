#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next= NULL;
    }
};

class CircularList{

    Node* head;
    Node* tail;
public:
    CircularList(){
        head=tail=NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next=head;
        } 
        // Circular List without Head pointer
        // else{
        //     newNode->next=tail->next;
        //     tail->next=newNode;
        // }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is Empty" << endl;
            return;
        }
        else if(head==tail){
                delete head;
                head=tail=NULL;
        } else{
            Node* temp = head;
            head = head->next;
            tail->next=head;

            temp->next=NULL; 
            delete temp;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "LL is Empty" << endl;
            return;
        }
        if (head == tail) { 
            delete head;
            head = tail = NULL;
            return;
        } else{
            Node* temp = tail;
            Node* prev = head;

            while (prev->next != tail) {
                prev = prev->next;
            }
            
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void printLL() {
        if(head==NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;  
        while (temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main(){
    CircularList cll;
    cll.push_front(10);
    cll.push_front(20);
    cll.push_front(30);
    cll.push_front(40);
      
    cll.push_back(50);
    cll.push_back(60);

    cll.pop_front();
    cll.pop_front();

    cll.pop_back();

    cll.printLL();
    return 0;
}