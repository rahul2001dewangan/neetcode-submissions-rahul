class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == INT_MAX) {
                    q.push({nr, nc});
                    grid[nr][nc] = grid[r][c] + 1;
                }
            }
        }
    }
};
