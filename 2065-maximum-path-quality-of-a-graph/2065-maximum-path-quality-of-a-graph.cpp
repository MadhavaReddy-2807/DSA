class Solution {
public:
vector<int>visited;
void dfs(int& maxi,vector<int>&values,vector<vector<pair<int,int>>>&adj,int node,int time,int val,int maxtime)
{
    if(node==0)
    {
        maxi=max(maxi,val);
    }
    for(auto e:adj[node])
    {
        int u=e.first;
        int t=e.second;
        int new_val=0;
        if(visited[u]==0)
        {
            new_val=values[u];
        }
            if(t+time<=maxtime)
            {
             visited[u]++;
             dfs(maxi,values,adj,u,t+time,val+new_val,maxtime);
             visited[u]--;
            }
        
    }
}
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int,int>>>adj(values.size());
        visited.resize(values.size(),0);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            int t=e[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        int maxi=INT_MIN;
        visited[0]=1;
        dfs(maxi,values,adj,0,0,values[0],maxTime);
        return maxi;
    }
};