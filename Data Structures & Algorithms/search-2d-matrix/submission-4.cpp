class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n;
            int c = mid % n;
            if (target == matrix[r][c])
                return true;
            else if (target > matrix[r][c])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};