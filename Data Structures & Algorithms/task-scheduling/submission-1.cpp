class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for (char c : tasks) {
            f[c - 'A']++;
        }
        int maxf = *max_element(f.begin(), f.end());
        int count_max = 0;
        for (int i : f) {
            if (i == maxf)
                count_max++;
        }
        int intervals = (maxf - 1) * (n + 1) + count_max;
        return max((int)tasks.size(), intervals);
    }
};