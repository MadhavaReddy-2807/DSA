class Solution {
public:
vector<int>dp;
long long dfs( map<int,vector<int>>&buses,vector<vector<int>>& routes,int src,int tar)
{
    if(src==tar)
    {
        return 0;
    }
    // for all buses coming in that route
    long long ans=INT_MAX;
    for(int bus:buses[src])
    {
        if(dp[bus]==-1)
        {
            //for all the routes that the bus goes
            dp[bus]=1;
            for(int route:routes[bus])
            {
                ans=min(ans,1+dfs(buses,routes,route,tar));
            }
        }
    }
    return ans;
}
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
         map<int,vector<int>>buses;
         int n=routes.size();
         dp.resize(n,-1);
         for(int i=0;i<routes.size();i++)
         {
            for(auto route:routes[i])
            buses[route].push_back(i);
         }
         queue<pair<int,int>>q;
         q.push({source,0});
         while(!q.empty())
         {
            auto node=q.front();
            q.pop();
            int route=node.first;
            int steps=node.second;
            if(route==target)
            {
                return steps;
            }
             for(int bus:buses[route])
                {
                    if(dp[bus]==-1)
                    {
                        //for all the routes that the bus goes
                        dp[bus]=1;
                        for(int x:routes[bus])
                        {
                           q.push({x,1+steps});
                        }
                    }
                 }
            
         }
         return -1;
    }
};