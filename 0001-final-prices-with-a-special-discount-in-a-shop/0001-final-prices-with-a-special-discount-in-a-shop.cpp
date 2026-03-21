class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n=prices.size();
        vector<int>rough(n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                rough[i]=0;
                st.push(prices[i]);
            }
            else
            {
                while(!st.empty()&&st.top()>prices[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    rough[i]=0;

                }
                else
                {
                    rough[i]=st.top();
                }
                st.push(prices[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            prices[i]=prices[i]-rough[i];
        }
        return prices;
    }
};