class Solution {
public:
    stack<int>st;
    vector<int> asteroidCollision(vector<int>& a) {
        int i=0;
        int n=a.size();
        while(i<n)
        {
         if(a[i]<0)
         {
                while(!st.empty()&&(st.top()<abs(a[i]))&&st.top()>0)
                {
                    st.pop();
                }
                if(!st.empty()&&st.top()<0)
                {
                    st.push(a[i]);
                }
                if(st.empty())
                {
                    st.push(a[i]);
                }
                if(st.top()==abs(a[i]))
                {
                    st.pop();
                }
         }
         else
         {
            st.push(a[i]);
         }
         i++;
        }
        vector<int>result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};