class Solution {
public:
    bool Contains(unordered_map<char,int> a, unordered_map<char,int> b) {
        for (auto i : a)
            if (a[i.first] > b[i.first])
                return false;
        return true;
    }

    string minWindow(string s, string t) {
        string ans = "";
        if (s.size() < t.size())
            return ans;
        unordered_map<char,int> a,b;
        int l = 0, r = 0;
        for (char c : t) {
            a[c]++;
        }
        for (; r < s.size(); r++) {
            b[s[r]]++;
            while (Contains(a,b)) {
                if (ans == "" || ans.size() > r - l + 1)
                    ans = s.substr(l, r - l + 1);
                b[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};