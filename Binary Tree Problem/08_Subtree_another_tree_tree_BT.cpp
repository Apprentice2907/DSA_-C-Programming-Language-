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

bool isIdentical(Node* p, Node* q) {
    if (p == NULL || q == NULL) return p == q;
    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right) && p->data == q->data;
}

bool isSubtree(Node* root, Node* subroot) {
    if (root == NULL || subroot == NULL) {
        return root == subroot;
    }
    if (root->data == subroot->data && isIdentical(root, subroot)) {
        return true;
    }
    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

int main() {
    vector<int> p = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> q = {3,4,-1,-1,5,-1,-1};
    
    idx = -1;
    Node* root1 = buildTree(p);
    idx = -1;
    Node* root2 = buildTree(q);

    cout << "Tree built successfully!" << endl;
    cout << isSubtree(root1, root2) << endl;

    return 0;
}
