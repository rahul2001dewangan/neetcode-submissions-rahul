class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_set<int> s;
        s.reserve(nums.size());
        s.insert(nums.begin(), nums.end());
        int m = 0;
        for (int i : s) {
            if (s.find(i - 1) == s.end()) {
                int count = 1, curr = i;
                while (s.find(curr + 1) != s.end()) {
                    ++curr;
                    ++count;
                }
                if (count > m)
                    m = count;
            }
        }
        return m;
    }
};