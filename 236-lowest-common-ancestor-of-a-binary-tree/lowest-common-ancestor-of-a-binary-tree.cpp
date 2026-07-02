/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==NULL) return NULL;
        if(node->val==p->val || node->val==q->val) return node;

        TreeNode* leftn=solve(node->left,p,q);
        TreeNode* rightn=solve(node->right,p,q);

        if(leftn==NULL && rightn==NULL) return NULL;
        else if(leftn!=NULL && rightn==NULL) return leftn;
        else if(leftn==NULL && rightn!=NULL) return rightn;
        else return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};