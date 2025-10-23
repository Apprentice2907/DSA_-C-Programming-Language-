#include <iostream>
#include <vector>
#include <queue>
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

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
};

int sumTree(Node* root){
    if(root==NULL) return 0;
    int leftSum= sumTree(root->left);
    int rightSum= sumTree(root->right);

    root->data+=leftSum+rightSum;
    return root->data;
}

int main() {
    vector<int> list = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(list);

    cout<<"Before";
    preorder(root);
    cout<<endl;

    sumTree(root);

    cout<<"After";
    preorder(root);
    cout<<endl;

    return 0;
}
