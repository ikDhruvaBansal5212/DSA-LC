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
    bool solve(TreeNode* l, TreeNode* R){
        if(l==NULL && R==NULL) return true;

        if(l==NULL || R==NULL || l->val!=R->val){
            return false;
        }

        return solve(l->left,R->right) && solve(l->right,R->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};