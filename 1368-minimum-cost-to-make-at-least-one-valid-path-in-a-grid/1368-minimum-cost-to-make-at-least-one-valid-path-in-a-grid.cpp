class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        q.push({0,{0,0}});
        while(!q.empty())
        {
            int steps=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==m-1&&y==n-1)
            {
                return steps;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0||ny<0||nx>=m||ny>=n)
                {
                    continue;
                }
                if((i+1)!=grid[x][y])
                {
                    if(steps+1<dis[nx][ny])
                    {
                        dis[nx][ny]=1+steps;
                        q.push({steps+1,{nx,ny}});
                    }
                }
                else
                {
                    if(steps<dis[nx][ny])
                    {
                        dis[nx][ny]=steps;
                        q.push({steps,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};