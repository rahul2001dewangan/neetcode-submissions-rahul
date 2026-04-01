class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> mp;
        int l = 0, i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (mp.find(s[j]) != mp.end()) {
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            l = max(l, j - i + 1);
        }
        return l;
    }
};