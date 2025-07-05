class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        
        int count=0;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            count++;
            int x=q.size();
           while(x--)
           {
             auto[i,j]=q.front();
             q.pop();
             for(auto d:dir)
             {
                int nx=i+d[0];
                int ny=j+d[1];
                if(nx>=m||ny>=n||nx<0||ny<0||visited[nx][ny]||grid[nx][ny]==0)
                {
                    continue;
                }
                visited[nx][ny]=1;
                grid[nx][ny]=2;
                q.push({nx,ny});
             }
           }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return count-1;
    }
};