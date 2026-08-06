class Solution {
public:
class dsu{
    public:
    vector<int>parent;
    vector<int>size;
    dsu(int n)
    {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findparent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void unionset(int u,int v)
    {
        int up_u=findparent(u);
        int up_v=findparent(v);
        if(up_u==up_v)
        {
            return;
        }
        if(size[up_u]<size[up_v])
        {
            size[up_v]+=size[up_u];
            parent[up_u]=up_v;
        }
        else
          {
            size[up_u]+=size[up_v];
            parent[up_v]=up_u;
          }
    }
};
vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
void build(vector<vector<int>>&grid,dsu*d)
{
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                for(auto dir:dirs)
                {
                    int ni=i+dir[0];
                    int nj=j+dir[1];
                    if(ni<0||nj<0||ni>=m||nj>=n||!grid[ni][nj])
                    {
                        continue;
                    }
                    d->unionset(ni*n+nj,i*n+j);
                }
            }
        }
    }
}
int components(int m,int n,dsu*d,vector<vector<int>>& grid)
{
    unordered_set<int>st;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                st.insert(d->findparent(i*n+j));
            }
        }
    }
    return st.size();
}
    int minDays(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
        dsu*d=new dsu(m*n+1);
        build(grid,d);
       int x=components(m,n,d,grid);
       if(x>1)
       {
        return 0;
       }
       int count=0;
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                count++;
            dsu*d=new dsu(m*n+1);
            grid[i][j]=0;
            build(grid,d);
            int x=components(m,n,d,grid);
            if(x>1)
            {
                return 1;
            }
            grid[i][j]=1;
            }
        }
       }
       if(count==1)
       {
        return 1;
       }
       if(count==0)
       {
        return 0;
       }
       return 2;
    }
};