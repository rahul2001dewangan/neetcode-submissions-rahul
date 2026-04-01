class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> a, b;
        for (char c : s1) {
            a[c]++;
        }
        int l = 0, r = l + s1.size() - 1;
        for (int k = 0; k <= r; k++) {
            b[s2[k]]++;
        }
        while (l <= r && l < s2.size() && r < s2.size()) {
            for (auto i : a)
                cout << i.first << " " << i.second << " ";
            cout << endl;
            for (auto i : b)
                cout << i.first << " " << i.second << " ";
            cout << endl << endl;
            if (a == b)
                return true;
            b[s2[l]]--;
            if (b[s2[l]] == 0)
                b.erase(s2[l]);
            l++;
            r++;
            b[s2[r]]++;
        }
        return false;
    }
};