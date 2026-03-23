class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<long long>>> dp;

    vector<long long> func(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i>=m||j>=n)
        {
            return {INT_MIN,INT_MAX};
        }

        if(dp[i][j][0] != LLONG_MIN) return dp[i][j];

        if(i==m-1&&j==n-1)
        {
            return dp[i][j] = {(long long)grid[i][j],(long long)grid[i][j]};
        }

        vector<long long> result(2);
        auto down = func(i+1,j,m,n,grid);
        auto right = func(i,j+1,m,n,grid);

        if(grid[i][j] < 0)
        {
            result[0] = max(grid[i][j]*down[1], grid[i][j]*right[1]);
            result[1] = min(grid[i][j]*down[0], grid[i][j]*right[0]);
        }
        else
        {
            result[0] = max(grid[i][j]*down[0], grid[i][j]*right[0]);
            result[1] = min(grid[i][j]*down[1], grid[i][j]*right[1]);
        }

        return dp[i][j] = result;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MIN)));

        auto x = func(0,0,m,n,grid);

        if(x[0] < 0) return -1;
        return x[0] % mod;
    }
};