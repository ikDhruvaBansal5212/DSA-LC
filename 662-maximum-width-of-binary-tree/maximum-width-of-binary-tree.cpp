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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;     //{val,ind}   
        q.push({root,0});
        unsigned long long res=0;
        while(!q.empty()){
            int s=q.size();
            res=max(res,q.back().second-q.front().second+1);
            for(int i=0;i<s;i++){
                TreeNode* node=q.front().first;
                unsigned long long ind=q.front().second;
                q.pop();
                if(node->left) q.push({node->left,2*ind+1});
                if(node->right) q.push({node->right,2*ind+2});
            }
        }
        return res;
    }
};