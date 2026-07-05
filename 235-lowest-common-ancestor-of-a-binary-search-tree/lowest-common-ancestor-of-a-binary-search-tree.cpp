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
    TreeNode* solve(TreeNode* node, int a, int b){
        if(node==NULL) return NULL;

        if(node->val>a && node->val<b) return node;
        if(node->val==a || node->val==b) return node;

        if(node->val<a && node->val<b) return solve(node->right,a,b);
        else{
            return solve(node->left,a,b);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a;
        int b;
        if(p->val<q->val){
            a=p->val;
            b=q->val;
        }else{
            a=q->val;
            b=p->val;
        }
        return solve(root,a,b);
    }
};