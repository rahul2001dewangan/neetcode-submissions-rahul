class Solution {
public:
    int rows, cols;
    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '*';
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int a = 0; a < 4; a++) {
                int nr = r + dr[a];
                int nc = c + dc[a];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols ||
                    board[nr][nc] != 'O')
                    continue;
                q.push({nr, nc});
                board[nr][nc] = '*';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O')
                bfs(board, 0, i);
            if (board[rows - 1][i] == 'O')
                bfs(board, rows - 1, i);
        }
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][cols - 1] == 'O')
                bfs(board, i, cols - 1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};