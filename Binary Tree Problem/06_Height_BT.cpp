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
Node* buildTree(vector<int> tree) {
    idx++;
    if (tree[idx] == -1) return NULL;
    Node* root = new Node(tree[idx]);
    root->left = buildTree(tree);
    root->right = buildTree(tree);
    return root;
}


int height(Node* root){
    if(root==NULL) return 0;
    int lefth=height(root->left);
    int righth=height(root->right);
    return max(lefth,righth)+1;
}

int count(Node* root){
    if(root==NULL) return  0;
    int leftc=count(root->left);
    int rightc=count(root->right);
    return leftc+rightc+1;
}

int sum(Node* root){
    if(root==NULL) return  0;
    int lefts =sum(root->left);
    int rights =sum(root->right);
    return lefts+rights+root->data;
}

int main(){
    vector<int> preorder ={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root= buildTree(preorder);

    cout<<"Height : "<<height(root)<<endl;
    cout<<"Count : "<<count(root)<<endl;
    cout<<"Sum : "<<sum(root)<<endl;
    return 0;
}