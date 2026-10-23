class Solution {
public:
    bool recur(string& s1, string& s2, string& s3, int i, int j, int k,
               vector<vector<int>>& dp) {
        if (k == s3.size() && i == s1.size() && j == s2.size())
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i < s1.size() && j < s2.size() && s3[k] == s1[i] && s3[k] == s2[j])
            return dp[i][j] = recur(s1, s2, s3, i + 1, j, k + 1, dp) ||
                              recur(s1, s2, s3, i, j + 1, k + 1, dp);
        if (i < s1.size() && s3[k] == s1[i])
            return dp[i][j] = recur(s1, s2, s3, i + 1, j, k + 1, dp);
        if (j < s2.size() && s3[k] == s2[j])
            return dp[i][j] = recur(s1, s2, s3, i, j + 1, k + 1, dp);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() < s3.length())
            return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return recur(s1, s2, s3, 0, 0, 0, dp);
    }
};