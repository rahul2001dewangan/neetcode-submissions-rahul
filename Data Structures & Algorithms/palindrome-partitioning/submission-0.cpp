class Solution {
public:
    bool isPal(string& s, int& st, int& en) {
        int i = st, j = en;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    void palPar(string& s, vector<vector<string>>& ans, vector<string>& part,
                int st) {
        if (st == s.size()) {
            ans.push_back(part);
            return;
        }
        for (int en = st; en < s.size(); en++) {
            int l = en - st + 1;
            if (isPal(s, st, en)) {
                    part.push_back(s.substr(st, l));
                    palPar(s, ans, part, en + 1);
                    part.pop_back();
                }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        palPar(s, ans, part, 0);
        return ans;
    }
};