class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, mf = 0, ml = 0;
        for ( ; r < s.size(); r++) {
            mp[s[r]]++;
            mf = max(mf, mp[s[r]]);
            while ((r - l + 1) - mf > k) {
                mp[s[l]]--;
                l++;
            }
            ml = max(ml, r - l + 1);
        }
        return ml;
    }
};