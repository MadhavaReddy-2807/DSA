class Solution {
public:
const int mod=1e9+7;
int dp[1000][1000];
int func(int i,int j)
{
    if(i==0&&j==0)
    {
        return 1;
    }
    if(i<=0||j<=0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int count=0;
    if(i==j)
    {
        count+=func(i-1,j-1);
        count=count%mod;
        count+=func(i-2,j-2);
        count=count%mod;
        count+=func(i-2,j-1);
        count=count%mod;
        count+=func(i-1,j-2);
        count=count%mod;
    }
    else if(i>j)
    {
        count=count%mod;
        count+=func(i-2,j-1);
        count+=func(i-2,j);
        count=count%mod;
    }
    else
    {
        count=count%mod;
        count+=func(i-1,j-2);
        count=count%mod;
        count+=func(i,j-2);
        count=count%mod;
    }
    return dp[i][j]=count;
}
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n,n);
    }
};