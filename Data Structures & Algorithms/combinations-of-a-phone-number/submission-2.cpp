class Solution {
public:
    vector<string> ans;
    string mp[10] = {"",    "",    "abc",  "def", "ghi",
                     "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void Letters(string& digits, string& s, int idx) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }
        string v = mp[digits[idx] - '0'];
        for (char c : v) {
            s += c;
            Letters(digits, s, idx + 1);
            s.erase(s.size() - 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        string s;
        Letters(digits, s, 0);
        return ans;
    }
};