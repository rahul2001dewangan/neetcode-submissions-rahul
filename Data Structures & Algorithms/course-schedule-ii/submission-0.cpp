class Solution {
public:
    bool topoDFS(int s, vector<vector<int>>& adj, vector<bool>& vis,
                 vector<bool>& rep, stack<int>& st) {
        vis[s] = true;
        rep[s] = true;
        for (auto& v : adj[s]) {
            if (!vis[v] && topoDFS(v, adj, vis, rep, st))
                return true;
            else if (rep[v])
                return true;
        }
        rep[s] = false;
        st.push(s);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<bool> rep(n, false);
        stack<int> st;

        for (auto& e : prerequisites)
            adj[e[1]].push_back(e[0]);

        for (int i = 0; i < n; i++)
            if (!vis[i] && topoDFS(i, adj, vis, rep, st))
                return {};

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};