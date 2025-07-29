class Solution {
public:
int dp[10005];
int func(int i,int n,vector<pair<int,int>>&a)
{
    if(a[i].second==n)
    {
        return 1;
    }
    if(i==a.size())
    {
        return 1e7;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int res=1e7;
    for(int j=i+1;j<a.size();j++)
    {
        if(a[j].first>a[i].second)
        {
            break;
        }
        res=min(res,1+func(j,n,a));
    }
    return dp[i]=res;
}
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++)
        {
            int mini=max(0,i-ranges[i]);
            int maxi=min(n,i+ranges[i]);
            a.push_back({mini,maxi});
        }
        memset(dp,-1,sizeof(dp));
        sort(a.begin(),a.end());
        int res=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            if(a[i].first==0)
            {
                res=min(res,func(i,n,a));
            }
        }
        return res>=1e7?-1:res;
    }
};