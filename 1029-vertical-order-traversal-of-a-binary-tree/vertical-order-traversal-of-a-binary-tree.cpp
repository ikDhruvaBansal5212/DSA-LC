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
    map<int, map<int, multiset<int>>> mp;

    void solve(TreeNode* root, int row, int col) {
        if (root == NULL)
            return;

        mp[col][row].insert(root->val);

        solve(root->left, row + 1, col - 1);
        solve(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);

        vector<vector<int>> res;

        for (auto &col : mp) {
            vector<int> temp;

            for (auto &row : col.second) {
                for (int val : row.second) {
                    temp.push_back(val);
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};