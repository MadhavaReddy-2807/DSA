class Solution {
public:
long long  dp[501][501][3];
bool visited[501][501][3];
 long long func(int i,int j,int m,int n,auto coins,int x)
 {
    if(i>=m||j>=n)
    {
        return INT_MIN;
    }
    long long val=0;
    long long res=INT_MIN;
    val=coins[i][j];
    if(i==m-1&&j==n-1)
    {
        if(val>=0)
        {
            return dp[i][j][x]=val;
        }
        else
        {
            if(x<2)
            {
                return dp[i][j][x]=0;
            }
            return dp[i][j][x]=val;
        }
    }
    if(visited[i][j][x]!=0)
    {
        return dp[i][j][x];
    }
   if(coins[i][j]>=0)
   {
     res=max(res,val+func(i+1,j,m,n,coins,x));
     res=max(res,val+func(i,j+1,m,n,coins,x));
   }
   else
   {
     if(x<2)
     {
        res=max(res,func(i+1,j,m,n,coins,x+1));
        res=max(res,func(i,j+1,m,n,coins,x+1));
     }
        res=max(res,val+func(i+1,j,m,n,coins,x));
        res=max(res,val+func(i,j+1,m,n,coins,x));
   }
   visited[i][j][x]=1;
    return dp[i][j][x]=res;

 }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp,-1,sizeof(dp));
        memset(visited,0,sizeof(visited));
        return func(0,0,coins.size(),coins[0].size(),coins,0);
    }
};