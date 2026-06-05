class Solution {
   public:
    unordered_map<int, vector<char>> mp;

    void Letters(string& digits, vector<string>& ans, string& s, int idx) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }

        vector<char> v = mp[digits[idx] - '0'];
        for (char c : v) {
            s += c;
            Letters(digits, ans, s, idx + 1);
            s.erase(s.size() - 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string s;
        Letters(digits, ans, s, 0);
        return ans;
    }
};