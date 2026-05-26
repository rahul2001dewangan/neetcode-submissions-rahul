/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int cnt = 0;
    int recur(TreeNode* root, int maxval) {
        if (!root)
            return 0;
        int good = root->val >= maxval;
        maxval = max(root->val, maxval);
        return good + recur(root->left, maxval) + recur(root->right, maxval);
    }
    int goodNodes(TreeNode* root) {
        return recur(root, INT_MIN);
    }
};
