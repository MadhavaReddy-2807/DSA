class Solution {
public:
const long long mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto r:roads)
        {
            adj[r[0]].push_back({1LL*r[1],1LL*r[2]});
            adj[r[1]].push_back({1LL*r[0],1LL*r[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        vector<long long>dis(n,LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0]=1;
        dis[0]=0;
        q.push({0,0});
        while(!q.empty())
        {
            long long cost=q.top().first;
            long long node=q.top().second;
            q.pop();
            if(cost>dis[node])
            {
                continue;
            }
            for(auto a:adj[node])
            {
                long long wt=a.second;
                long long neigh=a.first;
                
                if(dis[neigh]>(wt+cost))
                {
                    dis[neigh]=wt+cost;
                    q.push({dis[neigh],neigh});
                    ways[neigh]=ways[node];
                }
                else if(dis[neigh]==wt+cost)
                {
                    ways[neigh]=(ways[neigh]+ways[node])%mod;
                }
            }

        }
        return ways[n-1];

    }
};