class Solution {
   public:
    void subsets(vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans, int idx) {
        ans.push_back(subs);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            subs.push_back(nums[i]);
            subsets(nums, subs, ans, i + 1);
            subs.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subs;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subsets(nums, subs, ans, 0);
        return ans;
    }
};
