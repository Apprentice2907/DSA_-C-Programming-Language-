#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void allPaths(TreeNode* root, string path, vector<string> &ans) {
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }
        if(root->left){
            allPaths(root->left,path+"->"+to_string(root->left->val),ans);
        }
        if(root->right){
            allPaths(root->right,path+"->"+to_string(root->right->val),ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);
        allPaths(root,path,ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    for(string path : result) {
        cout << path << endl;
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
