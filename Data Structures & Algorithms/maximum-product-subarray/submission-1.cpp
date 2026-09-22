class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pmax = nums[0], pmin = nums[0], ans = nums[0];
        for (int i = 1; i < n; i++) {
            int x = nums[i];
            int nmax = max({pmax * x, pmin * x, x});
            int nmin = min({pmax * x, pmin * x, x});
            ans = max(ans, nmax);
            pmax = nmax;
            pmin = nmin;
        }
        return ans;
    }
};