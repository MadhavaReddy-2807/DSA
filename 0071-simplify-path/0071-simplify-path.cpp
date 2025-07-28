class Solution {
public:
string extractword(int &i,string s)
{
    string res="";
    while(i<s.length()&&s[i]!='/')
    {
        res+=s[i];
        i++;
    }
    cout<<res;
    cout<<s[i];
    return res;
}
    string simplifyPath(string s) {
        int i=0;
        stack<string>st;
        while(i<s.length())
        {
            string rough="";
            if(s[i]=='/')
            {
                i++;
                continue;
            }
            else if(s[i]=='.')
            {
                string rough="";
                while(i<s.length()&&s[i]!='/')
                {
                    rough+=s[i];
                    i++;
                }
                // i--;
               if(rough=="..")
               {
                if(!st.empty())
                {
                    // cout<<i;
                  st.pop();
                }
               }
               else if(rough==".")
               {

               }
               else
               {
                 st.push(rough);
               }
            }
            else
            {
                st.push(extractword(i,s));
                // i--;
            }
            i++;
        }
        vector<string>rough;
        while(!st.empty())
        {
            rough.push_back(st.top());
            // cout<<"sf";
            st.pop();
        }
        reverse(rough.begin(),rough.end());
        string res="";
        for(int i=0;i<rough.size();i++)
        {
            res+='/';
            res+=rough[i];
        }
        if(rough.size()==0)
        {
            return "/";
        }
        return res;
    }
};