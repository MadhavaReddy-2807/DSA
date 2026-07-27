class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        for (auto &e : edges) {
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [moves, node] = pq.top();
            pq.pop();

            if (moves != dist[node]) continue;

            for (int i = 0; i < n; i++) {
                if (adj[node][i] == INT_MAX) continue;

                int nd = moves + adj[node][i] + 1;

                if (nd < dist[i]) {
                    dist[i] = nd;
                    pq.push({nd, i});
                }
            }
        }

        int result = 0;

        // Count original nodes
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                result++;
        }

        // Count subdivided nodes
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cnt = e[2];

            int left = 0, right = 0;

            if (dist[u] <= maxMoves)
                left = maxMoves - dist[u];

            if (dist[v] <= maxMoves)
                right = maxMoves - dist[v];

            result += min(cnt, left + right);
        }

        return result;
    }
};