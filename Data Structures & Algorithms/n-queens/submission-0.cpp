class Solution {
public:
    vector<vector<string>> ans;

    void queens(int& n, int col, vector<string>& board, vector<bool>& left,
                vector<bool>& ld, vector<bool>& ud) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (left[row] || ld[row + col] || ud[n - 1 + col - row])
                continue;
            board[row][col] = 'Q';
            left[row] = true;
            ld[row + col] = true;
            ud[n - 1 + col - row] = true;
            queens(n, col + 1, board, left, ld, ud);
            board[row][col] = '.';
            left[row] = false;
            ld[row + col] = false;
            ud[n - 1 + col - row] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) {
            return {};
        }
        vector<string> board(n, string(n, '.'));
        vector<bool> left(n, false), ld(2 * n - 1, false), ud(2 * n - 1, false);
        queens(n, 0, board, left, ld, ud);
        return ans;
    }
};