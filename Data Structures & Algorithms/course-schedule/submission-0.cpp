class Solution {
public:
    bool isCycleDFS(int s, vector<vector<int>>& edges, vector<bool>& vis,
                    vector<bool>& rep) {
        vis[s] = true;
        rep[s] = true;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];
            if (u == s) {
                if (!vis[v] && isCycleDFS(v, edges, vis, rep))
                    return true;
                else if (rep[v])
                    return true;
            }
        }
        rep[s] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);
        vector<bool> rep(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycleDFS(i, prerequisites, vis, rep))
                return false;
        }
        return true;
    }
};
