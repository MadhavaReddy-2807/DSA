class Solution {
public:
vector<vector<int>>adj;
int func(int mask,vector<vector<vector<int>>>&dp,int prev_l,int prev_r,string &label)
{
    if(label[prev_l]!=label[prev_r])
    {
        return 0;
    }
    if(dp[mask][prev_l][prev_r]!=-1)
    {
        return dp[mask][prev_l][prev_r];
    }
    int ans=2;
    int maxi=INT_MIN;
    for(auto e:adj[prev_l])
    {
        for(auto e1:adj[prev_r])
        {
            if(e!=e1)
            {
                if (((mask >> e) & 1) == 0 &&
                    ((mask >> e1) & 1) == 0)                {
                    mask=mask^(1<<e);
                    mask=mask^(1<<e1);
                    maxi=max(maxi,func(mask,dp,e,e1,label));
                    mask=mask^(1<<e);
                    mask=mask^(1<<e1);
                }
            }
        }
    }
    if(maxi==INT_MIN)
    {
        maxi=0;
    }
    return dp[mask][prev_l][prev_r]=ans+maxi;
}
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        adj.resize(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int sizeofmask=pow(2,n);
        vector<vector<vector<int>>>dp(sizeofmask,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        //odd length
        int maxi=INT_MIN;
        int mask=0;
        for(int i=0;i<n;i++)
        {
            mask=mask|(1<<i);
            maxi=max(maxi,func(mask,dp,i,i,label)-1);
            mask=mask^(1<<i);
        }
        //even length
        for(int i=0;i<n;i++)
        {
            for(auto e:adj[i])
            {
                mask=mask|(1<<i);
                mask=mask|(1<<e);
                maxi=max(maxi,func(mask,dp,i,e,label));
                mask=mask^(1<<e);
                mask=mask^(1<<i);
            }
        }
    
        return maxi;
    }
};