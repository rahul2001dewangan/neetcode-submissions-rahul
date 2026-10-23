class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() < s2.size())
            swap(s1, s2);
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;
        vector<bool> dp(n + 1, false);
        for (int i = 0; i <= m; i++) {
            vector<bool> nextdp(n + 1, false);
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    nextdp[0] = true;
                }
                if (i > 0 && s3[i + j - 1] == s1[i - 1] && dp[j])
                    nextdp[j] = true;
                if (j > 0 && s3[i + j - 1] == s2[j - 1] && nextdp[j - 1])
                    nextdp[j] = true;
            }
            dp = nextdp;
        }
        return dp[n];
    }
};