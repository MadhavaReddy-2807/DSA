class Solution {
public:
    vector<string>valid;
    vector<char>colors;
    int mod=1e9+7;
    void generate(int i,int n,int prev,string s)
    {
        if(i==n)
        {
            valid.push_back(s);
            return;
        }
        for(int idx=0;idx<colors.size();idx++)
        {
            if(idx!=prev)
            {
                generate(i+1,n,idx,s+colors[idx]);
            }
        }

    }
    bool check(string a,string b)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
            {
                return false;
            }
        }
        return true;
    }
    int func(int i,int prev,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 1;
        }
        int ways=0;
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        for(int idx=0;idx<valid.size();idx++)
        {
            if(prev==-1||check(valid[prev],valid[idx]))
            {
            ways=(ways+func(i+1,idx,n,dp))%mod;
            }
        }
        return dp[i][prev+1]=ways;
    }
    int numOfWays(int n) {
        colors={'R','G','B'};
        string s="";
        generate(0,3,-1,s);
        vector<vector<int>>dp(n+1,vector<int>(valid.size()+1,-1));
        return func(0,-1,n,dp);
    }
};