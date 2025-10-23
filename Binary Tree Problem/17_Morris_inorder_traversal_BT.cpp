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


vector<int> morrisInorderTraversal(Node* root) {
    Node* curr= root;
    vector<int> result;
    while(curr!=NULL){
        if(curr->left==NULL){
            result.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* IP = curr->left;
            while(IP->right!=NULL && IP->right!=curr){
                IP=IP->right;
            }
            if(IP->right==NULL){
                IP->right=curr;
                curr=curr->left;
            }
            else{
                IP->right=NULL;  // restore the tree
                result.push_back(curr->data);
                curr=curr->right;  
            }
        }
    }
    return result;   
}


int main(){
    vector<int> tree = {1, 2, -1, -1, 4, -1, 7, -1, -1};
    Node* root = buildTree(tree);

    vector<int> inorder = morrisInorderTraversal(root);

    // print the result
    for(int val : inorder){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
