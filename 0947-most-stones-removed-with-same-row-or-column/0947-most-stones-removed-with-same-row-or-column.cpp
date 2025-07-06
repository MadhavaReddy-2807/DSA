class disjointset{
    public:
    vector<int>size;
    vector<int>parent;
    disjointset(int n)
    {
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    void unionset(int u,int v)
    {
        int up_u=findparent(u);
        int up_v=findparent(v);
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
    int findparent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=INT_MIN;
        int maxcol=INT_MIN;
        for(auto e:stones)
        {
            maxrow=max(maxrow,e[0]);
            maxcol=max(maxcol,e[1]);
        }
        disjointset d(maxrow+maxcol+2);
        for(auto s:stones)
        {
            int u=s[0];
            int v=s[1]+maxrow+1;
            if(d.findparent(u)==d.findparent(v))
            {
                continue;
            }
            else
            {
                d.unionset(u,v);
            }
        }
        vector<int>parent=d.parent;
        vector<int>size=d.size;
        int count=0;
        for(int i=0;i<maxrow+maxcol+2;i++)
        {
            if(size[i]>1&&parent[i]==i)
            {
                count++;
            }
        }
        return stones.size()-count;

    }
};