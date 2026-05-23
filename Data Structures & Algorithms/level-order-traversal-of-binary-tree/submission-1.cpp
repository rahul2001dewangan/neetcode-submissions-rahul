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
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> l;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* x = q.front();
                q.pop();
                l.push_back(x->val);
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            ans.push_back(l);
        }
        return ans;
    }
};