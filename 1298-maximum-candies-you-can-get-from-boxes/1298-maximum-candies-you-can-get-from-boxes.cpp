class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& tot_keys, vector<vector<int>>& containedBoxes, vector<int>& init) {
        queue<int>q;
        int n=candies.size();
        vector<int>visited(n,0);
        unordered_set<int>canvisit,keys;
        for(auto x:init)
        {
            if(status[x])
            {
                visited[x]=1;
                q.push(x);
            }
            else
            {
                canvisit.insert(x);
            }
        }
        int res=0;
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            res+=candies[x];
                for(auto k:tot_keys[x])
                {
                    keys.insert(k);
                }
            for(auto s:canvisit)
            {
                if(!visited[s]&&keys.find(s)!=keys.end())
                {
                    visited[s]=1;
                    q.push(s);
                }
            }
            for(auto box:containedBoxes[x])
            {
                if(!visited[box])
                {
                    if(status[box]||(keys.find(box)!=keys.end()))
                    {
                        visited[box]=1;
                        q.push(box);
                    }
                    else
                    {
                        canvisit.insert(box);
                    }
                }
            }
        }
        return res;
      
    }
};