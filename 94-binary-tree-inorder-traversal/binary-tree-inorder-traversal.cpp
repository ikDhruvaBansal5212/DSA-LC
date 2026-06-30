/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>res;

    void solve(TreeNode *node){
        if(node==nullptr){
            return;
        }

        solve(node->left);
        res.push_back(node->val);
        solve(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};