class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int i : nums) {
            unordered_map<int, int> nextdp;
            for (auto& d : dp) {
                nextdp[d.first + i] += d.second;
                nextdp[d.first - i] += d.second;
            }
            dp = nextdp;
        }
        return dp[target];
    }
};