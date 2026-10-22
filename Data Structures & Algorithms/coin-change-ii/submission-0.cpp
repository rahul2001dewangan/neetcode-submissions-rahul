class Solution {
public:
    int recur(int amount, vector<int>& coins, vector<vector<int>>& dp,
              int idx) {
        if (amount == 0)
            return 1;
        if (idx >= coins.size() || amount < 0)
            return 0;
        if (dp[amount][idx] != -1)
            return dp[amount][idx];
        return dp[amount][idx] = recur(amount - coins[idx], coins, dp, idx) +
                                 recur(amount, coins, dp, idx + 1);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
        return recur(amount, coins, dp, 0);
    }
};