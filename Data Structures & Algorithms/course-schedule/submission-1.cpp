class Solution {
public:
    bool isCycleDFS(int s, vector<vector<int>>& adj, vector<bool>& vis,
                    vector<bool>& rep) {
        vis[s] = true;
        rep[s] = true;
        for (auto& v : adj[s]) {
            if (!vis[v] && isCycleDFS(v, adj, vis, rep))
                return true;
            else if (rep[v])
                return true;
        }
        rep[s] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);
        vector<bool> rep(n, false);
        vector<vector<int>> adj(n);
        for (auto& e : prerequisites)
            adj[e[1]].push_back(e[0]);
        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycleDFS(i, adj, vis, rep))
                return false;
        }
        return true;
    }
};