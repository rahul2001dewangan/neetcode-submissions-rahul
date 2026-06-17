class Solution {
public:
    int rows, cols;
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
             vector<vector<bool>>& visited) {
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols ||
                    heights[nr][nc] < heights[r][c] || visited[nr][nc])
                    continue;
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> p, a;
        rows = heights.size();
        cols = heights[0].size();
        queue<pair<int, int>> qp, qa;
        vector<vector<bool>> vp(rows, vector<bool>(cols, false));
        vector<vector<bool>> va(rows, vector<bool>(cols, false));
        for (int i = 0; i < cols; i++) {
            qp.push({0, i});
            vp[0][i] = true;
            qa.push({rows - 1, i});
            va[rows - 1][i] = true;
        }
        for (int i = 0; i < rows; i++) {
            qp.push({i, 0});
            vp[i][0] = true;
            qa.push({i, cols - 1});
            va[i][cols - 1] = true;
        }
        bfs(heights, qp, vp);
        bfs(heights, qa, va);
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (va[i][j] && vp[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};