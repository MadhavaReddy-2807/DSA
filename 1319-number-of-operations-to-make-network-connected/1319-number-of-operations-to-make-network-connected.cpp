class Solution {
public:
  int findparent(int u,vector<int>&parent)
  {
    if(parent[u]==u)
    {
        return u;
    }
    return parent[u]=findparent(parent[u],parent);
  }
  void unionbysize(int u,int v,vector<int>&parent,vector<int>&size)
  {
    int up_u=parent[u];
    int up_v=parent[v];
    if(up_u==up_v)
    {
        return;
    }
    if(size[up_u]<size[up_v])
    {
          parent[up_u]=up_v;
          size[up_v]+=size[up_u];
    }
    else
    {
        parent[up_v]=up_u;
        size[up_u]+=size[up_v];
    }
  }
    int makeConnected(int n, vector<vector<int>>& edges) {
       vector<int>size(n,1);
       vector<int>parent(n,0);
       for(int i=0;i<n;i++)
       {
        parent[i]=i;
       } 
       int count=0;
       for(int i=0;i<edges.size();i++)
       {
         int u=edges[i][0];
         int v=edges[i][1];
         if(findparent(u,parent)==findparent(v,parent))
         {
            count++;
         }
         else
         {
            unionbysize(u,v,parent,size);
         }
       }
       vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++)
       {
          adj[edges[i][1]].push_back(edges[i][0]);
          adj[edges[i][0]].push_back(edges[i][1]);
       }
       int dis=0;
      int c=0;
      for(int i=0;i<n;i++)
      {
        if(parent[i]==i)
        {
            c++;
        }
      }
       return count>=c-1?c-1:-1;
    }
};