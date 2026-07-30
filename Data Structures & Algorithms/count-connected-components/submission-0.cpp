class Solution {
   public:
    void dfs(int s, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[s] = true;
        for (auto& v : adj[s]) {
            if (!vis[v]) dfs(v, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};
