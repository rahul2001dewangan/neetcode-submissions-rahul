class Solution {
public:
    int loop(vector<int>& nums, int st, int en) {
        int a = 0, b = 0;
        for (int i = st; i <= en; i++) {
            int c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(loop(nums, 0, n - 2), loop(nums, 1, n - 1));
    }
};