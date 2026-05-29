class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for (char c : tasks) {
            f[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i : f) {
            if (i > 0)
                pq.push(i);
        }
        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> temp;
            while (cycle-- && !pq.empty()) {
                int x = pq.top();
                pq.pop();
                if (x - 1 > 0)
                    temp.push_back(x - 1);
                time++;
            }
            for (int i : temp) {
                pq.push(i);
            }
            if (pq.empty())
                break;
            time += cycle + 1;
        }
        return time;
    }
};