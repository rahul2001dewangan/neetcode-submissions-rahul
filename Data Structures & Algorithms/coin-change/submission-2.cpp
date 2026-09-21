class Solution {
public:
    int recur(vector<int>& coins, int a, vector<int>& dp) {
        if (a == 0)
            return 0;
        if (dp[a] != -2)
            return dp[a];
        int mn = INT_MAX;
        for (int c : coins) {
            if (c <= a) {
                int x = recur(coins, a - c, dp);
                if (x != -1)
                    mn = min(mn, x + 1);
            }
        }
        return dp[a] = (mn == INT_MAX ? -1 : mn);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return recur(coins, amount, dp);
    }
};