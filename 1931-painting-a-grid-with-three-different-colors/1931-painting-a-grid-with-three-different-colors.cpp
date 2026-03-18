class Solution {
public:
int mod=1e9+7;
vector<int>valid;
 void generate(int i,int m,int prev,int state)
    {
        if(i==m)
        {
            valid.push_back(state);
            return;
        }
        for(int j=1;j<=3;j++)
        {
            if(prev!=j)
            {
                generate(i+1,m,j,(state<<2)|j);
            }
        }
    }
bool check(int a,int prev,int m)
{
    int x=valid[a];
    int y=valid[prev];
    for(int i=0;i<m;i++)
    {
        if((x>>(m-i-1)*2&3)==((y>>(m-i-1)*2)&3))
        {
            return false;
        }
    }
    return true;
}
int func(int prev,int col,int n,int m,vector<vector<int>>&dp)
{
    if(col==n)
    {
        return 1;
    }
    if(dp[col][prev]!=-1)
    {
        return dp[col][prev];
    }
    int ways=0;
    for(int i=0;i<valid.size();i++)
    {
        if(i!=prev)
        {
            if(check(i,prev,m))
            {
                ways=(ways+func(i,col+1,n,m,dp))%mod;
            }
        }
    }
    return dp[col][prev]=ways;
}
    int colorTheGrid(int m, int n) {
        int prev=-1;
        generate(0,m,prev,0);
        int ways=0;
        vector<vector<int>>dp(n,vector<int>(valid.size(),-1));
        for(int i=0;i<valid.size();i++)
        {
            ways=(ways+func(i,1,n,m,dp))%mod;
        }
        return ways;
    }
};