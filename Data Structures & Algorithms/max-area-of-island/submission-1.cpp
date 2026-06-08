class Solution {
public:
    int rows, cols;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != 1)
            return 0;
        int area = 1;
        grid[r][c] = 0;
        area += dfs(grid, r + 1, c);
        area += dfs(grid, r, c + 1);
        area += dfs(grid, r - 1, c);
        area += dfs(grid, r, c - 1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        rows = grid.size();
        cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};