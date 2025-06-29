class Solution {
public:
void l(vector<vector<int>>&left,vector<vector<int>>&grid,int n)
{
    for(int i=0;i<=n+1;i++)
    {
        int index=-1; 
        for(int j=0;j<=n+1;j++)
        {
            if(grid[i][j]==0)
            {
                index=j;
            }
            else
            {
                left[i][j]=j-index-1;
            }
        }
    }
}
void r(vector<vector<int>>&left,vector<vector<int>>&grid,int n)
{
    for(int i=0;i<=n+1;i++)
    {
        int index=-1; 
        for(int j=n+1;j>=0;j--)
        {
            if(grid[i][j]==0)
            {
                index=j;
            }
            else
            {
                left[i][j]=index-j-1;
            }
        }
    }
}
void d(vector<vector<int>>&left,vector<vector<int>>&grid,int n)
{
    for(int i=0;i<=n+1;i++)
    {
        int index=-1; 
        for(int j=n+1;j>=0;j--)
        {
            if(grid[j][i]==0)
            {
                index=j;
            }
            else
            {
                left[j][i]=index-j-1;
            }
        }
    }
}
void u(vector<vector<int>>&left,vector<vector<int>>&grid,int n)
{
    for(int i=0;i<=n+1;i++)
    {
        int index=-1; 
        for(int j=0;j<=n+1;j++)
        {
            if(grid[j][i]==0)
            {
                index=j;
            }
            else
            {
                left[j][i]=j-index-1;
            }
        }
    }
}
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
       vector<vector<int>>grid(n+2,vector<int>(n+2,0));
       vector<vector<int>>left(n+2,vector<int>(n+2,-1));
       vector<vector<int>>right(n+2,vector<int>(n+2,-1));
       vector<vector<int>>up(n+2,vector<int>(n+2,-1));
       vector<vector<int>>down(n+2,vector<int>(n+2,-1));
    //    set<pair<int,int>>s;
    //    for(auto i:mines)
    //    {
    //     s.insert({i[0],i[1]});
    //    } 
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
                grid[i][j]=1;
        }
      }
    for(auto m:mines)
    {
        grid[m[0]+1][m[1]+1]=0;
    }
      l(left,grid,n);
      r(right,grid,n);
      d(down,grid,n);
      u(up,grid,n);
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
      }
      int res=-1;
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
            if(grid[i][j])
            {
                res=max(res,min({left[i][j],right[i][j],up[i][j],down[i][j]}));
            }
        }
      }
       return res+1;
    }
};