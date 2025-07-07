class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                mp[routes[i][j]].push_back(i);//bus that come to that busstop
            }
        }
        if(source==target)
        {
            return 1;
        }
        queue<int>q;
        vector<int>visited(routes.size(),false);
        for(int i=0;i<mp[source].size();i++)
        {
            visited[mp[source][i]]=true;
            q.push({mp[source][i]});//buses that go from that busstop
        }
        int count=0;
        while(!q.empty())
        {
            count++;
            int x=q.size();
            while(x--)
            {
                int bus=q.front();
                q.pop();
                for(auto stop:routes[bus])//what are the stops that can be reached from that bus
                {
                    if(stop==target)
                    {
                        return count;
                    }
                    for(auto next:mp[stop])//what buses come to that stop
                    {
                        if(!visited[next])
                        {
                            visited[next]=1;
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};