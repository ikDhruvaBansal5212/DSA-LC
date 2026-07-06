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
class BSTIterator {
    private:
    void pushALL(TreeNode* node) {
        while (node != nullptr) {
            mystack.push(node);
            node = node->left;
        }
    }
public:
    stack<TreeNode*> mystack;
    BSTIterator(TreeNode* root) {
        pushALL(root);
    }
    
    int next() {
        TreeNode *tempnode=mystack.top();
        mystack.pop();
        pushALL(tempnode->right);
        return tempnode->val;
    }
    
    bool hasNext() {
        return !mystack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */