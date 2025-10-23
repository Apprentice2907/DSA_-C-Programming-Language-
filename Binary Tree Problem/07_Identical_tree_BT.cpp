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
    bool isLeftSame = isIdentical(p->left, q->left);
    bool isRightSame = isIdentical(p->right, q->right);
    return isLeftSame && isRightSame && p->data == q->data;
}

int main() {
    vector<int> p = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> q = {1,2,-1,-1,3,4,-1,-1,5  ,-1,-1};
    
    idx = -1;
    Node* root1 = buildTree(p);
    idx = -1;
    Node* root2 = buildTree(q);

    cout << "Tree built successfully!" << endl;
    cout << isIdentical(root1, root2);
    return 0;
}
