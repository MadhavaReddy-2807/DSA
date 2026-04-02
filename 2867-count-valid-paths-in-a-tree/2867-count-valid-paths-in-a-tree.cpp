vector<int>isprime;
void compute()
{
    int n=100000;
    isprime.resize(n+1,1);
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
        for(int j=i*i;j<=n;j+=i)
        {
            isprime[j]=0;
        }
        }
    }
}
class seg{
    public:
    int prime;
    int nonprime;
};
class Solution {
public:
long long count=0;
seg dfs(int node,vector<int>&visited,vector<vector<int>>&adj)
{
    visited[node]=1;
    seg v;
    v.nonprime=!isprime[node];
    v.prime=isprime[node];
    vector<seg>rough;
    for(auto &n:adj[node])
    {
        if(!visited[n])
        {
            seg r;
           r=dfs(n,visited,adj);
            count+=1LL*r.prime*v.nonprime+1LL*r.nonprime*v.prime;
           if(isprime[node])
           {
             v.prime+=r.nonprime;
           }
           else
           {
            v.nonprime+=r.nonprime;
            v.prime+=r.prime;
           }
        }
    }
    return v;


}
    long long countPaths(int n, vector<vector<int>>& edges) {
        compute();
        vector<vector<int>>adj(n+1);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
           vector<int>visited(n+1,0);
           dfs(1,visited,adj);
        return count;
        }
};