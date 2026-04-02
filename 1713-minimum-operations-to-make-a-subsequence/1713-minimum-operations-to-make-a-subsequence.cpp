class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<target.size();i++)
        {
            mp[target[i]]=i;
        }
        vector<int>rough;
        for(auto &a:arr)
        {
            if(mp.count(a))
            {
              rough.push_back(mp[a]);
            }
        }
        vector<int>st;
        for(int i=0;i<rough.size();i++)
        {
            if(st.empty())
            {
                st.push_back(rough[i]);
            }
            else
            {
                auto it=lower_bound(st.begin(),st.end(),rough[i]);
                if(it==st.end())
                {
                    st.push_back(rough[i]);
                }
                else
                {
                    *it=rough[i];
                }
            }
        }
        return target.size()-st.size();
    }
};