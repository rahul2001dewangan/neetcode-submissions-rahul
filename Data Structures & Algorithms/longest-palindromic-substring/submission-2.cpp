class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        string ans = s.substr(0,1);
        int rl = 1;
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > rl) {
                    rl = r - l + 1;
                    ans = s.substr(l, rl);
                }
                l--;
                r++;
            }
            l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > rl) {
                    rl = r - l + 1;
                    ans = s.substr(l, rl);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};