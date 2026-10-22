class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size())
            swap(text1, text2);
        int m = text1.length(), n = text2.length();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int dia = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = dia + 1;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                dia = temp;
            }
        }
        return dp[n];
    }
};