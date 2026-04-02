class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int tar) {
        if (l <= r) {
            int m = (l + r) / 2;
            if (tar == nums[m])
                return m;
            else if (tar < nums[m])
                return bs(nums, l, m - 1, tar);
            else
                return bs(nums, m + 1, r, tar);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size() - 1, target);
    }
};