#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* first=head;
        ListNode* sec=head->next;
        ListNode* prev=NULL;
        while(first!=NULL && sec!=NULL){
            ListNode* third = sec->next;
            sec->next=first;
            first->next=third;

            if(prev!=NULL){
                prev->next=sec;
            } else{
                head=sec;
            }
            prev=first;
            first=third;
            if(third!=NULL){
                sec=third->next;
            } else{
                sec=NULL;
            }
        }
        return head;
    }
};

// Helper to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.swapPairs(head);

    cout << "After swapping pairs: ";
    printList(head);

    return 0;
}
