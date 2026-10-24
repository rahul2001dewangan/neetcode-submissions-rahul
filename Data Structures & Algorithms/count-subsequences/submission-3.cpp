class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> dp(n + 1, 0);
        vector<int> nextdp(n + 1, 0);
        dp[n] = nextdp[n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[j] = nextdp[j];
                if (s[i] == t[j])
                    dp[j] += nextdp[j + 1];
            }
            nextdp = dp;
        }
        return dp[0];
    }
};