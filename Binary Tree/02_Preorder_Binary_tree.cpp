#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
     
    Node(int val){
        data = val;
        left = right = NULL;
    } 
};

static int idx = -1;
Node* buildTree(vector<int> tree){
    idx++;
    if(tree[idx] == -1)
        return NULL;
    Node* root = new Node(tree[idx]);

    root->left = buildTree(tree);
    root->right = buildTree(tree);

    return root;
};

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
};


int main(){
    vector<int> tree = {1, 2, -1, -1, 4, -1, 7, -1, -1};
    Node* root = buildTree(tree);

    // cout << root->data<<endl;
    // cout << root->left->data <<endl;
    // cout << root->right->data<<endl;

    preorder(root);
    return 0;
}
