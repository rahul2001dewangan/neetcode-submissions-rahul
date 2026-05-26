class Solution {
public:
    bool dfs(TreeNode* root, long low, long high) {
        if (!root)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }
    bool isValidBST(TreeNode* root) { return dfs(root, LONG_MIN, LONG_MAX); }
};