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
    bool same(TreeNode* a, TreeNode* b) {
        if (!a || !b)
            return a == b;
        return a->val == b->val && same(a->left, b->left) &&
               same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if (!root)
            return false;
        return same(root, sub) || isSubtree(root->left, sub) ||
               isSubtree(root->right, sub);
    }
};