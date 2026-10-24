class Solution {
public:
    int recur(vector<vector<int>>& mat, int i, int j, int p,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() ||
            mat[i][j] <= p) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int u = recur(mat, i - 1, j, mat[i][j], dp);
        int d = recur(mat, i + 1, j, mat[i][j], dp);
        int l = recur(mat, i, j - 1, mat[i][j], dp);
        int r = recur(mat, i, j + 1, mat[i][j], dp);
        return dp[i][j] = 1 + max({u, d, l, r});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, recur(matrix, i, j, -1, dp));
            }
        }
        return mx;
    }
};