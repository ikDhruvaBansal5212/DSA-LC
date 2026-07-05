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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        TreeNode* res=root;
        while(true){
            if(root->val>val){
                if(root->left) root=root->left;
                else{
                    TreeNode* nn=new TreeNode(val);
                    root->left=nn;
                    root=root->left;
                    break;
                }
            }
            else{
                if(root->right) root=root->right;
                else {
                    TreeNode* nn=new TreeNode(val);
                    root->right=nn;
                    root=root->right;
                    break;
                }
            }
        }
        return res;

    }
};