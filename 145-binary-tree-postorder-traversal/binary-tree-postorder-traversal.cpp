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
    void solve(TreeNode* node){
        if(node==nullptr) return;

        solve(node->left);
        solve(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};