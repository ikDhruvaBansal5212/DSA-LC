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
    int res=INT_MIN;

    int solve(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int l=max(0,solve(node->left));
        int r=max(0,solve(node->right));
        res=max(res,l+r+node->val);
        return max(l,r)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int d=solve(root);
        return res;
    }
};