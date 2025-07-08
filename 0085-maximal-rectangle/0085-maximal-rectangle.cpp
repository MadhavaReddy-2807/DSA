class Solution {
public:
int func(vector<int>a)
{
    int n=a.size();
    vector<int>left(n,0);
    vector<int>right(n,0);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            left[i]=-1;
        }
        else
        {
            left[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            right[i]=n;
        }
        else
        {
            right[i]=st.top();
        }
        st.push(i);
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" "<<right[i];
        maxi=max(maxi,a[i]*(abs(right[i]-left[i])-1));
    }
    cout<<endl;
    return maxi;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>prev(n,0);
        int res=INT_MIN;
        for(int i=0;i<m;i++)
        {
            vector<int>current(n,0);
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    current[j]=0;
                }
                else
                {
                    current[j]=1+prev[j];
                }
            }
            prev=current;
           res=max(res,func(current));
        }
        return res;
    }
};