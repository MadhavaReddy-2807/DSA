class Solution {
public:
vector<vector<int>>dirs={{1,1},{1,-1},{-1,-1},{-1,1}};
int dp[501][501][5][2];
int func(int i,int j,vector<vector<int>>&grid,int current,int dir,int times)
{
        int m=grid.size();
        int n=grid[0].size();
      int ni=i+dirs[dir][0];
      int nj=j+dirs[dir][1];
      int ans=1;
      if(dp[i][j][dir][times]!=-1)
      {
        return dp[i][j][dir][times];
      }
       if(ni<0||nj<0||ni>=m||nj>=n||grid[ni][nj]==current||grid[ni][nj]==1)
       {
          
       }
       else
       {
        ans=max(ans,1+func(ni,nj,grid,grid[ni][nj],dir,times));
       }
       if(times==0)
       {
          int x=i+dirs[(dir+1)%4][0];
          int y=j+dirs[(dir+1)%4][1];
          if(x<0||y<0||x>=m||y>=n||grid[x][y]==current||grid[x][y]==1)
            {
                    
            }
            else
            {
            ans=max(ans,1+func(x,y,grid,grid[x][y],(dir+1)%4,1));
            }          
       }
       return dp[i][j][dir][times]=ans;
}
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                     res=max(res,1);
                   for(int dir=0;dir<4;dir++)
                   {
                     int ni=i+dirs[dir][0];
                     int nj=j+dirs[dir][1];
                     if(ni<0||nj<0||ni>=m||nj>=n||grid[ni][nj]!=2)
                     {
                        continue;
                     }
                     res=max(res,1+func(ni,nj,grid,2,dir,0));
                   }
                }
            }
        }
        return res;
    }
};