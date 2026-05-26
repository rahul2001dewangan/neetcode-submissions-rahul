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
    int kse = -1;
    int cnt = 0;
    void recur(TreeNode* root, int k) {
        if (!root)
            return;
        recur(root->left, k);
        if (++cnt == k) {
            kse = root->val;
            return;
        }
        recur(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        recur(root, k);
        return kse;
    }
};