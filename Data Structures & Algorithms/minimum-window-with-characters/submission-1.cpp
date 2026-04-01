class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, si = -1, cnt = 0, minl = INT_MAX, n = t.size(), m = s.size();
        mp.reserve(n);
        for (char c : t)
            mp[c]++;
        for (; r < m; r++) {
            if (mp[s[r]]-- > 0)
                cnt++;
            while (cnt == n) {
                if (r - l + 1 < minl) {
                    minl = r - l + 1;
                    si = l;
                }
                if (++mp[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return si == -1 ? "" : s.substr(si, minl);
    }
};