class Solution {
public:
    bool detect(int src, int dest, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) {
                return true;
            }

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push(adjacentNode);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();

        vector<vector<int>> adj(V + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> vis(V + 1, 0);

            // Check if u and v are already connected
            if (detect(u, v, adj, vis)) {
                return {u, v};
            }

            // Add edge only if it does not create a cycle
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};