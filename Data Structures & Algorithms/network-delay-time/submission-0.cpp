class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        while (!pq.empty()) {
            int u = pq.top().second;
            int sd1 = pq.top().first;
            pq.pop();
            if (sd1 > dis[u])
                continue;
            for (auto& v : adj[u]) {
                int node = v.first;
                int d = v.second;
                if (dis[node] > sd1 + d) {
                    dis[node] = sd1 + d;
                    pq.push({dis[node], node});
                }
            }
        }
        int maxt = INT_MIN;
        for (int i = 1; i < n + 1; i++) {
            if (dis[i] == INT_MAX)
                return -1;
            maxt = max(maxt, dis[i]);
        }
        return maxt;
    }
};