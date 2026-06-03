class Solution {
public:
    void parantheses(int& n, int o, int c, string s, vector<string>& ans) {
        if (o == n && c == n) {
            ans.push_back(s);
            return;
        }
        if (o < n) {
            parantheses(n, o + 1, c, s + '(', ans);
        }
        if (c < o) {
            parantheses(n, o, c + 1, s + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parantheses(n, 0, 0, "", ans);
        return ans;
    }
};
