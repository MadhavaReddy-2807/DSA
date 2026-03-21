class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
       stack<pair<int,int>>st;
       map<int,int>mp;
        for(int i=0;i<logs.size();i++)
        {
            string id="";
            string time="";
            string type="";
            string s=logs[i];
            int j=0;
            for(j=0;j<s.length();j++)
            {
                if(s[j]==':')
                {
                    break;
                }
                id=id+s[j];
            }
            j++;
            for(;j<s.length();j++)
            {
                if(s[j]==':')
                {
                    break;
                }
                type=type+s[j];
            }
            j++;
            for(;j<s.length();j++)
            {
                time=time+s[j];
            }
            if(type=="start")
            {
                st.push({stoi(id),stoi(time)});
                st.push({-1,0});
            }
            else
            {
                int x=0;
                while(st.top().first!=stoi(id))
                {
                   x+=st.top().second;
                   st.pop();
                }
                int starttime=st.top().second;
                st.pop();
                mp[stoi(id)]+=(stoi(time)-starttime+1-x);
                st.push({-1,stoi(time)-starttime+1});
            }
        }
        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            result[i]=mp[i];
        }
        return result;

    }
};