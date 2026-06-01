class Solution {
public:
    void recursion(vector<int>& nums, vector<int>& subset,
                   vector<vector<int>>& ans, int i) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        recursion(nums, subset, ans, i + 1);
        subset.pop_back();
        recursion(nums, subset, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        recursion(nums, subset, ans, 0);
        return ans;
    }
};