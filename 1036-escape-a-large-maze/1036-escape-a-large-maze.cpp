class Solution {
public:
    unordered_set<long long> st;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    long long encode(int x, int y) {
        return (long long)x * 1000001 + y;
    }

    bool search(int sx, int sy, int tx, int ty, int limit) {
        unordered_set<long long> visited;
        queue<pair<int,int>> q;
        q.push({sx, sy});
        visited.insert(encode(sx, sy));

        while (!q.empty()) {
            if ((int)visited.size() > limit) return true;  // not trapped

            auto [x, y] = q.front();
            q.pop();

            if (x == tx && y == ty) return true;  // found target!

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000) continue;
                long long key = encode(nx, ny);
                if (visited.count(key) || st.count(key)) continue;
                visited.insert(key);
                q.push({nx, ny});
            }
        }
        return false;  // trapped and didn't find target
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        st.clear();
        for (auto& x : blocked) {
            st.insert(encode(x[0], x[1]));
        }
        int limit = blocked.size() * blocked.size();

        bool x = search(source[0], source[1], target[0], target[1], limit);
        bool y = search(target[0], target[1], source[0], source[1], limit);
        return x && y;
    }
};