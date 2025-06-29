class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string state="";
       for(int i=0;i<2;i++)
       {
        for(int j=0;j<3;j++)
        {
            state+='0'+board[i][j];
        }
       }
       vector<vector<int>>nei={
        {1,3},
        {0,2,4},
        {1,5},
        {0,4},
        {1,3,5},
        {2,4}
       };
       queue<pair<string,int>>q;
       q.push({state,0});
       unordered_set<string>visited;
       visited.insert(state);
       while(!q.empty())
       {
        auto [start,steps]=q.front();
        q.pop();
        int zero=start.find('0');
        if(start=="123450")
        {
            return steps;
        }
        for(auto x:nei[zero])
        {
            string newstate=start;
            swap(newstate[zero],newstate[x]);
            if(visited.find(newstate)==visited.end())
            {
                q.push({newstate,steps+1});
                visited.insert(newstate);
            }
        }
        }
       
       return -1;
    }
};