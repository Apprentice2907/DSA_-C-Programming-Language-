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

void topView(Node* root) {
    if (!root) return;
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int hd = it.second;
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->data;
        }
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    for (auto it : mp) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> list = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(list);
    cout << "Top View: ";
    topView(root);
    return 0;
}
