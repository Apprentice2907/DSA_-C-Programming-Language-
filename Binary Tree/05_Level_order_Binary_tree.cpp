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

void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop(); 
        if(curr==NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            } else{
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left!=NULL) q.push(curr->left);
        if (curr->right!=NULL) q.push(curr->right);
    }
}

int main() {
    vector<int> tree = {1, 2, -1, -1, 4, -1, 7, -1, -1};
    Node* root = buildTree(tree);
    levelOrder(root);
    return 0;
}
