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
    int msum=INT_MIN;
    int Sum(TreeNode* root) {
        if (!root)
            return 0;
        int ls = max(0,Sum(root->left));
        int rs = max(0,Sum(root->right));
        int s = ls + root->val + rs;
        msum = max(msum, s);
        return max(ls, rs) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        Sum(root);
        return msum;
    }
};