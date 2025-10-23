#include<iostream>
#include<vector>
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
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) return NULL;
    Node* root = new Node(nodes[idx]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);
    return root;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

int diameter(Node* root) {
    if (root == NULL) return 0;

    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = height(root->left) + height(root->right) + 1;

    return max(d3, max(d1, d2));
}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    
    idx = -1;
    Node* root = buildTree(nodes);

    cout << "Diameter of the tree: " << diameter(root) << endl;

    return 0;
}

