class Solution {
public:
    void palPar(string& s, vector<vector<string>>& ans, vector<string>& part,
                int st, vector<vector<bool>>& isPal) {
        if (st == s.size()) {
            ans.push_back(part);
            return;
        }
        for (int en = st; en < s.size(); en++) {
            if (isPal[st][en]) {
                part.push_back(s.substr(st, en - st + 1));
                palPar(s, ans, part, en + 1, isPal);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1]))
                    isPal[i][j] = true;
            }
        }
        palPar(s, ans, part, 0, isPal);
        return ans;
    }
};