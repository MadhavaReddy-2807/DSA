class Solution {
public:
int mod=1e9+7;
int dp[301][401];
int func(int index,int count,map<int,int>&mp)
{
    if(index<0)
    {
        if(count==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[index][count]!=-1)
    {
        return dp[index][count];
    }
    if(mp.find(index)!=mp.end()&&mp[index]!=count)
    {
        return 0;
    }
    long long ans=0;
    for(int i=0;i<=min(index,count);i++)
    {
        ans+=func(index-1,count-i,mp);
        ans=ans%mod;
    }
    return dp[index][count]=ans;
}
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        map<int,int>mp;
        memset(dp,-1,sizeof(dp));
        for(auto r:requirements)
        {
            mp[r[0]]=r[1];
        }
        if(mp.count(0)&&mp[0]!=0)
        {
            return 0;
        }
        return func(n-1,mp[n-1],mp);
    }
};