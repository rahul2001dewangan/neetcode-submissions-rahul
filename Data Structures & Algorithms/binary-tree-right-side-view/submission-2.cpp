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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recur(ans, root, 0);
        return ans;
    }
    void recur(vector<int>& ans, TreeNode* root, int level) {
        if (!root)
            return;
        if (level == ans.size())
            ans.push_back(root->val);
        recur(ans, root->right, level + 1);
        recur(ans, root->left, level + 1);
    }
};