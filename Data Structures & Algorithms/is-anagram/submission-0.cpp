class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> A(26, 0);
        vector<int> B(26, 0);
        for (int i = 0; i < s.size(); i++) {
            A[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            B[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (A[i] != B[i])
                return false;
        }
        return true;
    }
};
