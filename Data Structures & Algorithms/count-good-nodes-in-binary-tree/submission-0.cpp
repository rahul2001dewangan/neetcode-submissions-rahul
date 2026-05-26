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
    int cnt = 0;
    void recur(TreeNode* root, int maxval) {
        if (root == NULL) return;
        if (root->val >= maxval) {
            cnt++;
            maxval = root->val;
        }
        recur(root->left, maxval);
        recur(root->right, maxval);
    }
    int goodNodes(TreeNode* root) {
        recur(root, -101);
        return cnt;
    }
};
