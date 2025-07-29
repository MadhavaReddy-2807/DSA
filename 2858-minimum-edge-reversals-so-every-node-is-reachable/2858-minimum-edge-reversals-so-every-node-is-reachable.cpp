class Solution {
public:
vector<int>level;
vector<int>bfs(vector<vector<pair<int,int>>>&adj,int n,int index)
{
   vector<int>dis(n,INT_MAX);
   vector<int>result(n);
   queue<pair<int,int>>q;
   q.push({index,0});
   vector<int>visited(n,0);
   visited[index]=1;
   int t=0;
   while(!q.empty())
   {
    int node=q.front().first;
    int wt=q.front().second;
    q.pop();
    for(auto a:adj[node])
    {
      int x=a.first;
      int cost=a.second;
      if(!visited[x])
      {
        visited[x]=1;
        dis[x]=wt+cost;
        t+=cost;
        q.push({x,wt+cost});
      }
    }
   }
   result[index]=t;
   for(int i=0;i<n;i++)
   {
    if(i!=index)
    {
        result[i]=t+level[i]-2*dis[i];
    }
   }
   return result;

}
void dfs(vector<vector<pair<int,int>>>&adj,int node,int l,vector<int>&visited)
{
  level[node]=l;
  visited[node]=1;
  for(auto a:adj[node])
  {
     if(!visited[a.first])
     {
        dfs(adj,a.first,l+1,visited);
     }
  }
}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        vector<int>result(n);
        level.resize(n);
        vector<int>visited(n,0);
        dfs(adj,0,0,visited);
       result=bfs(adj,n,0);
        return result;
    }
};