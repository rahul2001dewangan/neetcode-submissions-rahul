class Solution {
public:
    int recur(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
        if (j == w2.size())
            return w1.size() - i;
        if (i == w1.size())
            return w2.size() - j;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (w1[i] == w2[j])
            return dp[i][j] = recur(w1, w2, i + 1, j + 1, dp);
        return dp[i][j] = 1 + min({recur(w1, w2, i, j + 1, dp),
                                   recur(w1, w2, i + 1, j, dp),
                                   recur(w1, w2, i + 1, j + 1, dp)});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return recur(word1, word2, 0, 0, dp);
    }
};