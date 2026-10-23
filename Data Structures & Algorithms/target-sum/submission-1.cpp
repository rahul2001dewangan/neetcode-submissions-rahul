class Solution {
public:
    int sum;
    int recur(int target, int idx, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if (target == 0 && idx == n)
            return 1;
        if (idx == n || target > sum || target < -sum)
            return 0;
        if (dp[target + sum][idx] != -1)
            return dp[target + sum][idx];
        return dp[target + sum][idx] =
                   recur(target - nums[idx], idx + 1, nums, dp) +
                   recur(target + nums[idx], idx + 1, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(2 * sum + 1, vector<int>(n, -1));
        return recur(target, 0, nums, dp);
    }
};