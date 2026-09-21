class Solution {
public:
    int recur(vector<int>& coins, int a, vector<int>& dp) {
        if (a == 0)
            return 0;
        int mn = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= a) {
                int x = dp[a - coins[i]] == -2 ? recur(coins, a - coins[i], dp)
                                               : dp[a - coins[i]];
                if (x != -1)
                    mn = min(mn, x + 1);
            }
        }
        return dp[a] = mn == INT_MAX ? -1 : mn;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return recur(coins, amount, dp);
    }
};