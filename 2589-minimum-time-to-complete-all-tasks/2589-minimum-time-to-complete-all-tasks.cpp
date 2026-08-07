class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto &a,auto &b){
            if(a[1]==b[1])
            {
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        unordered_set<int>st;
        for(auto t:tasks)
        {
            int start=t[0];
            int end=t[1];
            int duration=t[2];
            for(int i=start;i<=end&&duration;i++)
            {
                if(st.find(i)!=st.end())
                {
                    duration--;
                }
            }
         
            for(int i=end;i>=start&&duration;i--)
            {
                if(st.find(i)==st.end())
                {
                duration--;
                st.insert(i);
                }
                // cout<<i;
            }
        }
        return st.size();
    }
};