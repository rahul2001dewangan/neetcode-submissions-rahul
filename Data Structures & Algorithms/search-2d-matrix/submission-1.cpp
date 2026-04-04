class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size()-1, n = matrix[0].size()-1;
        int lm = 0, rm = m, ln = 0, rn = n;
        int midr, midn;
        while (lm <= rm) {
            midr = lm + (rm - lm) / 2;
            if (matrix[midr][0] <= target && matrix[midr][n] >= target)
                break;
            else if (target < matrix[midr][0])
                rm = midr - 1;
            else 
                lm = midr + 1;
        }
        while (ln <= rn) {
            midn = ln + (rn - ln) / 2;
            if (matrix[midr][midn] == target)
                return true;
            else if (target < matrix[midr][midn])
                rn = midn - 1;
            else
                ln = midn + 1;
        }
        return false;
    }
};