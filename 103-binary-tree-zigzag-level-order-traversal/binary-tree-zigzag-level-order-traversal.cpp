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
    vector<vector<int>>res;

    void solve(TreeNode* node){
        if(node==NULL) return;

        queue<TreeNode*>q;
        q.push(node);
        vector<int>temp;
        int flag=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
                TreeNode* start = q.front();
                int value=start->val;
                temp.push_back(value);
                q.pop();
                if(start->left) q.push(start->left);
                if(start->right) q.push(start->right);
            }
            if(flag==0){
                    res.push_back(temp);
                    flag=1;
                }
                else{
                    reverse(temp.begin(),temp.end());
                    res.push_back(temp);
                    flag=0;
                }
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root);
        return res;
    }
};