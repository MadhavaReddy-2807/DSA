class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Min-heap: {total_cost, stops_used, current_node}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for (const auto& flight : flights) {
            grid[flight[0]][flight[1]] = flight[2];
        }

        // visited[node][stops] = minimum cost to reach node with stops
        vector<vector<int>> visited(n, vector<int>(k + 2, INT_MAX));
        q.push({0, 0, src});
        visited[src][0] = 0;

        while (!q.empty()) {
            auto [cost, stops, node] = q.top();
            q.pop();

            if (node == dst) return cost;
            if (stops > k) continue;

            for (int i = 0; i < n; ++i) {
                if (grid[node][i]) {
                    int newCost = cost + grid[node][i];
                    if (newCost < visited[i][stops + 1]) {
                        visited[i][stops + 1] = newCost;
                        q.push({newCost, stops + 1, i});
                    }
                }
            }
        }

        return -1;
    }
};
