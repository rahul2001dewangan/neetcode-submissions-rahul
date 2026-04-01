class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> r(9, vector<int>(9));
        vector<vector<int>> c(9, vector<int>(9));
        vector<vector<int>> s(9, vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int box = (i / 3) * 3 + j / 3;
                    if (r[i][num] || c[j][num] || s[box][num])
                        return false;
                    r[i][num] = c[j][num] = s[box][num] = 1;
                }
            }
        }
        return true;
    }
};