class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[m-1][n-1]=grid[m-1][n-1]>0?1:1-grid[m-1][n-1];
        for(int i=m-2;i>=0;i--)
        {
            dp[i][n-1]=max(1,dp[i+1][n-1]-grid[i][n-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            dp[m-1][i]=max(1,dp[m-1][i+1]-grid[m-1][i]);
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=min(dp[i][j],max(1,dp[i][j+1]-grid[i][j]));
                dp[i][j]=min(dp[i][j],max(1,dp[i+1][j]-grid[i][j]));
            }
        }
        return dp[0][0];
    }
};