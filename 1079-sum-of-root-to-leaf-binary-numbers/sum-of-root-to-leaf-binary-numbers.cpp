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
    int dfs(TreeNode* node, string s) {
        if (node == nullptr)
            return 0;
        s += char(node->val + '0');

        if (node->left == nullptr && node->right == nullptr) {
            return stoi(s, nullptr, 2);
        }

        return dfs(node->left, s) + dfs(node->right, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, "");
    }
};