class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      string start="0000";
      unordered_set<string>st(deadends.begin(),deadends.end());
      unordered_set<string>visited;
      queue<pair<string,int>>q;
      q.push({start,0});
      visited.insert(start);
      while(!q.empty())
      {
        auto[curr,steps]=q.front();
        q.pop();
        if(curr==target)
        {
            return steps;
        }
        if(st.find(curr)!=st.end())
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            char c=curr[i];
            vector<int> dir={-1,1};
            for(int j=0;j<2;j++)
            {
                curr[i]=(c-'0'+dir[j]+10)%10+'0';
                if((visited.find(curr)==visited.end()))
                {
                    visited.insert(curr);
                    q.push({curr,steps+1});
                }
            }
            curr[i]=c;
        }

      }
      return -1;  
    }
};