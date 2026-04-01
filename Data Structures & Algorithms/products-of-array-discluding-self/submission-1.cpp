class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p = 1, s = 1;
        for (int i : nums) {
            ans.push_back(p);
            p *= i;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= s;
            s *= nums[i];
        }
        return ans;
    }
};