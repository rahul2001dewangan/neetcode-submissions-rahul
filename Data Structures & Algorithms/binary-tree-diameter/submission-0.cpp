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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lt = height(root->left);
        int rt = height(root->right);
        return max(lt, rt) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        int cd = height(root->left) + height(root->right);
        return max(cd, max(ld, rd));
    }
};