class Solution {
public:
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            if (up[node][j - 1] != -1)
                up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if ((diff >> j) & 1)
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n + 1, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, -1));

        dfs(1, -1);

        return {};
    }
};
