class NodeValue {
public:
    int minNode, maxNode, sum;

    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
    int ans = 0;

    NodeValue solve(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        return NodeValue(INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};