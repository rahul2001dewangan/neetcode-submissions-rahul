class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string sub = s.substr(j, i - j);
                    if (find(wd.begin(), wd.end(), sub) != wd.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};