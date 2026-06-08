class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<int>>& grid, int r, int c, int& sum) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != 1)
            return;
        sum += 1;
        grid[r][c] = 0;
        dfs(grid, r + 1, c, sum);
        dfs(grid, r, c + 1, sum);
        dfs(grid, r - 1, c, sum);
        dfs(grid, r, c - 1, sum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSum = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int sum = 0;
                    dfs(grid, i, j, sum);
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }
};