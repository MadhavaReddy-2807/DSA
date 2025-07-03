class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++)
        {
            while(!st.empty()&&st.top()>num[i]&&k>0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        if(k>0)
        {
           string result="";
           while(!st.empty())
           {
                result+=st.top();
                st.pop();
           } 
           reverse(result.begin(),result.end());
           result=result.substr(0,result.length()-k);
           int index=0;
           for(int i=0;i<result.length();i++)
            {
                if(result[i]!='0')
                {
                    index=i;
                    break;
                }
            }
           return result.substr(index)==""?"0":result.substr(index);
        }
        else
        {
            string result="";
             while(!st.empty())
           {
                result+=st.top();
                st.pop();
           } 
            reverse(result.begin(),result.end());
            int index;
            for(int i=0;i<result.length();i++)
            {
                if(result[i]!='0')
                {
                    index=i;
                    break;
                }
            }
           return result.substr(index)==""?"0":result.substr(index);
        }
        return "";
    }
};