class Solution {
public:
map<int,int>mp;
long long res=0;
void dfs(int node,int mask,vector<int>&visited,vector<vector<pair<int,char>>>&adj)
{
    visited[node]=1;
    for(auto x:adj[node])
    {
        char c=x.second;
        int a=x.first;
        if(!visited[a])
        {
            mask=mask^(1<<(c-'a'));
            res+=mp[mask];
            int newmask=mask;
            for(int i=0;i<26;i++)
            {
                res+=mp[newmask^(1<<i)];
            }
            mp[mask]++;
            dfs(a,mask,visited,adj);
            mask=mask^(1<<(c-'a'));
        }
    }
}
    long long countPalindromePaths(vector<int>& parent, string s) {
        vector<vector<pair<int,char>>>adj(s.length());
        for(int i=1;i<parent.size();i++)
        {
            if(parent[i]!=-1)
            {
                int u=i;
                int v=parent[i];
                adj[u].push_back({v,s[i]});
                adj[v].push_back({u,s[i]});
            }
        }
        vector<int>visited(s.length(),0);
        mp[0]=1;
        dfs(0,0,visited,adj);
        return res;
    }
};