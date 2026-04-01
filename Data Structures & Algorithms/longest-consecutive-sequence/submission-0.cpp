class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> s(nums.begin(), nums.end());
        int count = 1, m = 1, prev, it = 0;
        for (auto i : s) {
            if (it == 0) {
                prev = i;
                it++;
                continue;
            }
            if (i == prev + 1) {
                count++;
                m = max(count, m);
            } else
                count = 1;
            prev = i;
        }
        return m;
    }
};