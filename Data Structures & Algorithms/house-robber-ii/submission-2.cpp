class Solution {
   public:
    int loop(vector<int>& nums, int st, int en) {
        if (st == en) return nums[st];
        int a = nums[st];
        int b = max(nums[st], nums[st + 1]);
        for (int i = st + 2; i <= en; i++) {
            int c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(loop(nums, 0, n - 2), loop(nums, 1, n - 1));
    }
};