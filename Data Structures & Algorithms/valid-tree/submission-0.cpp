class Solution {
   public:
    bool isCycleDFS(int s, int p, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[s] = true;
        for (auto& v : adj[s]) {
            if (!vis[v]) {
                if (isCycleDFS(v, s, vis, adj)) return true;
            } else if (v != p)
                return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        if (isCycleDFS(0, -1, vis, adj)) return false;
        for (bool v : vis)
            if (!v) return false;
        return true;
    }
};
