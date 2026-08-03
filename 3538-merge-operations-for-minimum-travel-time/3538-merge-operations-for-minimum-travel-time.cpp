#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    long long memo[55][15][55];
    long long INF = 1e15;

    long long dp(int i, int skips, int last, int n, 
                const vector<int>& position, const vector<long long>& prefix) {
        if (i == n - 1) {
            return (skips == 0) ? 0 : INF;
        }

        if (memo[i][skips][last] != -1) {
            return memo[i][skips][last];
        }

        long long res = INF;
        long long rate = prefix[i] - (last > 0 ? prefix[last - 1] : 0);
        int max_j = min(n - 1, i + skips + 1);
        for (int j = i + 1; j <= max_j; ++j) {
            int skipped = j - i - 1;
            long long dist = position[j] - position[i];
            res = min(res, dist * rate + dp(j, skips - skipped, i + 1, n, position, prefix));
        }

        return memo[i][skips][last] = res;
    }

public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<long long> prefix(n, 0);
        prefix[0] = time[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + time[i];
        }

        memset(memo, -1, sizeof(memo));

        return (int)dp(0, k, 0, n, position, prefix);
    }
};