class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int c) {
        if (par[c] == c)
            return c;
        return par[c] = find(par[c]);
    }
    bool unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return false;
        if (rank[pa] == rank[pb]) {
            par[pb] = pa;
            rank[pa]++;
        } else if (rank[pa] > rank[pb]) {
            par[pb] = pa;
        } else {
            par[pa] = pb;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n + 1);
        rank.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
        for (auto& e : edges) {
            if (!unionByRank(e[0], e[1]))
                return e;
        }
        return {};
    }
};