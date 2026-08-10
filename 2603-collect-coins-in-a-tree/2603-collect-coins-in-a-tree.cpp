class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        vector<vector<int>>adj(coins.size());
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      for(auto &a:adj)
      {
         sort(a.begin(),a.end());
      }
      int ans=coins.size();
      queue<int>q;
      for(int i=0;i<coins.size();i++)
      {
         if(adj[i].size()==1)
         {
            if(coins[i]==0)
            {
              q.push(i);
            }
         }
      }
      while(!q.empty())
      {
        ans--;
        int u=q.front();
        q.pop();
        int v=adj[u][0];
        adj[u].pop_back();
        auto it=find(adj[v].begin(),adj[v].end(),u);
        adj[v].erase(it);
        if(adj[v].size()==1&&coins[v]==0)
        {
            q.push(v);
        }
      }
      for(int i=0;i<coins.size();i++)
      {
         if(adj[i].size()==1)
         {
            if(coins[i]==1)
            {
              q.push(i);
            }
         }
      }

        unordered_set<int>st;
      for(int i=0;i<2;i++)
      {
        int size=q.size();
        while(size--)
        {
            ans--;
            int u=q.front();
            q.pop();
            int v=adj[u][0];
            adj[u].pop_back();
            auto it=find(adj[v].begin(),adj[v].end(),u);
            adj[v].erase(it);
            if(adj[v].size()==1&&(st.find(v)==st.end()))
            {
                q.push(v);
                st.insert(v);
            }
        }
      }
      return max(2*(ans-1),0);
    }
};