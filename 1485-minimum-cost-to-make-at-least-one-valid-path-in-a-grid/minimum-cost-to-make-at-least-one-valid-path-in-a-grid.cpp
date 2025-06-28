class Solution {
public:
    vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        cost[0][0]=0;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0,0,0});
        while(!q.empty())
            {
                auto[curr,x,y]=q.top();
                q.pop();
                if(curr>cost[x][y])
                {
                    continue;
                }
                for(int i=0;i<4;i++)
                    {
                        int index=grid[x][y]-1;
                        int nx=x+dirs[i][0];
                        int ny=y+dirs[i][1];
                        if(nx<0||ny<0||nx>=m||ny>=n)
                        {
                            continue;
                        }
                        int newcost=i!=index;
                        if(newcost+curr<cost[nx][ny])
                        {
                            cost[nx][ny]=newcost+curr;
                            q.push({newcost+curr,nx,ny});
                        }
                    }
                
            }
        return cost[m-1][n-1];
    }
};