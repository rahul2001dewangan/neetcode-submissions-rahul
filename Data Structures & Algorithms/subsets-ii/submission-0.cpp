class Solution {
   public:
    void subsets(vector<int>& nums, vector<int>& subs, set<vector<int>>& ans, int idx) {
        if (idx == nums.size()) {
            ans.insert(subs);
            return;
        }
        subs.push_back(nums[idx]);
        subsets(nums, subs, ans, idx + 1);
        subs.pop_back();
        subsets(nums, subs, ans, idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subs;
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subsets(nums, subs, ans, 0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
