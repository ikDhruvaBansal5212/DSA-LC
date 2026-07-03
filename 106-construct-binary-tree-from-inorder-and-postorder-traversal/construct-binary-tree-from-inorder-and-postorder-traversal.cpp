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

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int start,int end,int& ind){
        if(start>end) return NULL;

        int rootval=postorder[ind];
        int i;
        for(i=start;i<=end;i++){
            if(inorder[i]==rootval)
            break;
        }
        ind--;
        TreeNode *root=new TreeNode(rootval);
        
        root->right=solve(postorder,inorder,i+1,end,ind);
        root->left=solve(postorder,inorder,start,i-1,ind);

        return root; 
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();

        int ind=n-1;
        return solve(postorder,inorder,0,n-1,ind);
    }
};