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

    TreeNode* solve(TreeNode* node, int target){
        if(node==NULL) return NULL;
        if(node->val==target){
            return node;
        }

        if(node->val<target){
            return solve(node->right,target);
        }
        else{
            return solve(node->left,target);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};