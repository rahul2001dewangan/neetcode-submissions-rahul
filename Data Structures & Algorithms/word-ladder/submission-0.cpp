class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        s.erase(beginWord);
        while (!q.empty()) {
            string w = q.front().first;
            int l = q.front().second;
            q.pop();
            if (w == endWord)
                return l;
            for (int i = 0; i < w.size(); i++) {
                char org = w[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    if (s.find(w) != s.end()) {
                        s.erase(w);
                        q.push({w, l + 1});
                    }
                }
                w[i] = org;
            }
        }
        return 0;
    }
};