class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(auto r:board)
        {
            for(auto e:r)
            {
                start+='0'+e;
            }
        }
        vector<vector<int>>nei={
            {1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}
        };
        unordered_set<string>st;
        st.insert(start);
        string target="123450";
        queue<pair<string,int>>q;
        q.push({start,0});
        while(!q.empty())
        {
            auto x=q.front().first;
            auto steps=q.front().second;
            q.pop();
            if(x==target)
            {
                return steps;
            }
            int pos=x.find('0');
            for(auto n:nei[pos])
            {
                string newx=x;
                swap(newx[n],newx[pos]);
                if(st.find(newx)==st.end())
                {
                    st.insert(newx);
                    q.push({newx,steps+1});
                }
            }
        }
        return -1;
    }
};