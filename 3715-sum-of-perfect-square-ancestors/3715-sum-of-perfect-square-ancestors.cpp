class Solution {
public:
map<int,int>squarefree;
int generate(int n)
{
    int freq=0;
    while(n%2==0)
    {
        freq++;
        n=n/2;
    }
    int res=1;
    if(freq%2)
    {
        res=res*2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        int freq=0;
        while(n%i==0)
        {
            freq++;
            n=n/i;
        }
        if(freq%2)
        {
            res=res*i;
        }
    }
    if(n!=1)
    {
        res=res*n;
    }
    return res;
}
void dfs(int node,vector<vector<int>>&adj,int parent,map<int,int>&mp,long long &res,vector<int>&nums)
{
    res+=mp[squarefree[nums[node]]];
    mp[squarefree[nums[node]]]++;
    for(auto e:adj[node])
    {
        if(e!=parent)
        {
            dfs(e,adj,node,mp,res,nums);
        }   
    }
    mp[squarefree[nums[node]]]--;
}
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
           squarefree[nums[i]]=generate(nums[i]);
        }
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,int>mp;
        long long res=0;
        dfs(0,adj,-1,mp,res,nums);
        return res;
    }
};