class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int node=i;
                int n=graph[i][j];
                adj[n].push_back(node);
            }
        }
        int n=graph.size();
        vector<int>in(graph.size(),0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                in[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(auto a:adj[node])
            {
                in[a]--;
                if(in[a]==0)
                {
                    q.push(a);
                }
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};