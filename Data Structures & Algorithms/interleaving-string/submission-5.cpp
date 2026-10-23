class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;
        if (m < n) {
            swap(s1, s2);
            swap(m, n);
        }
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = m; i >= 0; i--) {
            vector<bool> nextdp(n + 1, false);
            for (int j = n; j >= 0; j--) {
                if (i == m && j == n) {
                    nextdp[n] = true;
                    continue;
                }
                nextdp[j] = (i < m && s3[i + j] == s1[i] && dp[j]) ||
                            (j < n && s3[i + j] == s2[j] && nextdp[j + 1]);
            }
            dp = nextdp;
        }
        return dp[0];
    }
};