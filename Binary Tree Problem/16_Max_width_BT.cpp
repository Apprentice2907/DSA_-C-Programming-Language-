#include <bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxw=0;

        while(q.size()>0){
            int currLevelSize=q.size();
            unsigned long long stidx=q.front().second;
            unsigned long long endidx=q.back().second;

            maxw=max(maxw,(int)(endidx-stidx+1));

            for(int i=0;i<currLevelSize;i++){
                auto curr=q.front();
                q.pop();

                if(curr.first->left){
                    q.push({curr.first->left,curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,curr.second*2+2});
                }
            }
        }
        return maxw;
    }
};

TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    cout << "Maximum width: " << sol.widthOfBinaryTree(root) << endl;
    return 0;
}
