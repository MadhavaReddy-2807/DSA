class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size();
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1)
        {
            return -1;
        }
        q.push({0,{0,0}});
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;
        while(!q.empty())
        {
            int steps=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if((x==n-1)&&(y==n-1))
            {
                return steps+1;
            }
            for(auto d:dir)
            {
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]||visited[nx][ny])
                {
                   continue;
                }
                q.push({steps+1,{nx,ny}});
            }
        }
        return -1;
    }
};