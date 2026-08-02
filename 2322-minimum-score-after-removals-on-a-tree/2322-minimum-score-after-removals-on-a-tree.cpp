class Solution {
public:
vector<int>tin;
vector<int>tout;
void  dfs(vector<vector<int>>&adj,int node,vector<int>&nums,vector<int>&dp,vector<int>&visited,int &timer)
{
    dp[node]=nums[node];
    visited[node]=1;
    tin[node]=timer;
    timer++;
    for(auto a:adj[node])
    {
        if(!visited[a])
        {
            dfs(adj,a,nums,dp,visited,timer);
            dp[node]=dp[node]^dp[a];
        }
    }
    timer++;
    tout[node]=timer;
}
bool isancestor(int i,int j)
{
    if(tin[i]<tin[j]&&tout[i]>tout[j])// this to check if b is ancestor of a 
    {
        return true;
    }
    return false;
}
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>adj(nums.size());
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tin.resize(n);
        tout.resize(n);
        vector<int>dp(nums.size(),0);
        vector<int>visited(nums.size(),0);
        int timer=0;
        dfs(adj,0,nums,dp,visited,timer);
        int res=INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i!=j)
                {
                    if(isancestor(i,j))
                    {
                     int xor1=dp[j];
                     int xor2=dp[i]^dp[j];
                     int xor3=dp[0]^dp[i];
                      int mini=min({xor1,xor2,xor3});
                    int maxi=max({xor1,xor2,xor3});
                    res=min(res,maxi-mini);
                    }
                    else if(isancestor(j,i))
                    {
                        int xor1=dp[i];
                        int xor2=dp[j]^dp[i];
                        int xor3=dp[0]^dp[j];
                         int mini=min({xor1,xor2,xor3});
                    int maxi=max({xor1,xor2,xor3});
                    res=min(res,maxi-mini);
                    }   
                    else
                    {
                        int xor1=dp[i];
                        int xor2=dp[j];
                        int xor3=dp[0]^dp[i]^dp[j];
                         int mini=min({xor1,xor2,xor3});
                    int maxi=max({xor1,xor2,xor3});
                    res=min(res,maxi-mini);
                    }
                   
                }
            }
        }
        return res;
    }
};