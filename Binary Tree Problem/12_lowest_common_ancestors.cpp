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

Node* LCA(Node* root, int p, int q){
    if(root == NULL) return NULL;
    if(root->data == p || root->data == q) return root;

    Node* leftLCA = LCA(root->left, p, q);
    Node* rightLCA = LCA(root->right, p, q);

    if(leftLCA && rightLCA) return root;
    else if(leftLCA != NULL) return leftLCA;
    else return rightLCA;
}

int main() {
    vector<int> list = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(list);

    Node* lca = LCA(root, 4, 5);
    if(lca) cout << "LCA: " << lca->data << endl;

    return 0;
}
