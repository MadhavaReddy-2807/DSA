class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>a;
        int n=directions.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int sign;
           if(directions[i]=='R')
           {
            sign=1;
           }
           else
           {
            sign=-1;
           }
           mp[positions[i]]=i;
           a.push_back({positions[i],sign*healths[i]});
        }
        sort(a.begin(),a.end());
         stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            if(a[i].second<0)
            {
                int count=0;
                int val=-a[i].second;
                int index=a[i].first;
                while(!st.empty()&&st.top().first>0&&st.top().first<val)
                {
                    st.pop();
                    val--;
                }
                if(st.empty()||st.top().first<0)
                {
                    if(val!=0)
                    {
                        st.push({-val,index});
                    }
                }
               else if(!st.empty()&&st.top().first>val)
                {
                    int x=st.top().first;
                    int a=st.top().second;
                    st.pop();
                    x--;
                    if(x!=0)
                    {
                    st.push({x,a});
                    }
                }
               else  if(st.top().first==val)
                {
                    st.pop();
                }
            }
            else
            {
                st.push({a[i].second,a[i].first});
            }
        }
        vector<pair<int,int>>result;
        while(!st.empty())
        {
            cout<<st.top().first;
           result.push_back({mp[st.top().second],st.top().first});
           st.pop();
        }
        sort(result.begin(),result.end());
        vector<int>ans;
        for(auto it:result)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};