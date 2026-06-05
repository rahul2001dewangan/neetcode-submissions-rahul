class Solution {
public:
    int rows, cols;
    bool wordSearch(vector<vector<char>>& board, string& word, int i, int r,
                    int c) {
        if (i == word.size())
            return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            board[r][c] != word[i]) {
            return false;
        }
        board[r][c] = '*';
        bool found = wordSearch(board, word, i + 1, r + 1, c) ||
                     wordSearch(board, word, i + 1, r - 1, c) ||
                     wordSearch(board, word, i + 1, r, c + 1) ||
                     wordSearch(board, word, i + 1, r, c - 1);
        board[r][c] = word[i];
        return found;
    }
    bool exist(vector<vector<char>>& board, string& word) {

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                if (board[i][j] == word[0] && wordSearch(board, word, 0, i, j))
                    return true;
        }
        return false;
    }
};