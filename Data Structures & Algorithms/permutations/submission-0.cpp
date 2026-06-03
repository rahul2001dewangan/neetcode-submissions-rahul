class Solution {
public:
    void findPermutations(vector<int>& nums, vector<bool> taken,
                          vector<int> perm, vector<vector<int>>& ans) {
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (taken[i] == false) {
                taken[i] = true;
                perm.push_back(nums[i]);
                findPermutations(nums, taken, perm, ans);
                perm.pop_back();
                taken[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(), false);
        vector<int> perm;
        vector<vector<int>> ans;
        findPermutations(nums, taken, perm, ans);
        return ans;
    }
};