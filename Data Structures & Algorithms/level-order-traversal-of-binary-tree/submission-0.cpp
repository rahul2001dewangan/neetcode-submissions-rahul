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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> l;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            if (x) {
                l.push_back(x->val);
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            } else if (!x) {
                if (!q.empty()) {
                    ans.push_back(l);
                    l.clear();
                    q.push(NULL);
                }
                else{
                    ans.push_back(l);
                }
            }
        }
        return ans;
    }
};