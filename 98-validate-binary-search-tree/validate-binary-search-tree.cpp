class Solution {
public:
    bool solve(TreeNode* node, long long mini, long long maxi) {
        if (node == NULL)
            return true;

        if (node->val <= mini || node->val >= maxi)
            return false;

        return solve(node->left, mini, node->val) &&
               solve(node->right, node->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};