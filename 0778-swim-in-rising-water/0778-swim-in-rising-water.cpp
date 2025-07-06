class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=0;
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==n-1)
            {
                return cost;
            }
            for(auto d:dir)
            {
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&!visited[nx][ny])
                {
                    visited[nx][ny]=1;
                    int maxi=max(cost,grid[nx][ny]);
                    pq.push({maxi,{nx,ny}});
                }
            }
        }
        return -1;
        
    }
};