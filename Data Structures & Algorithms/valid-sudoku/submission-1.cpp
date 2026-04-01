class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[9] = {0}, c[9] = {0}, s[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int box = (i / 3) * 3 + j / 3;
                    int mask = 1 << num;
                    if (r[i] & mask || c[j] & mask || s[box] & mask)
                        return false;
                    r[i] |= mask;
                    c[j] |= mask;
                    s[box] |= mask;
                }
            }
        }
        return true;
    }
};