#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> tree) {
    idx++;
    if (tree[idx] == -1) return NULL;
    Node* root = new Node(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);
    return root;
}

void Kth(Node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<< root->data<<" ";
        return;
    }
    Kth(root->left,k-1);
    Kth(root->right,k-1);
}



int main() {
    vector<int> list = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(list);
    Kth(root,2);
    return 0;
}
