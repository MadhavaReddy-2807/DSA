class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n=a.size();
        vector<int>left(n,INT_MIN);
        vector<int>right(n,INT_MIN);
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],a[i-1]+i-1);
            // cout<<left[i]<<endl;
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],a[i+1]-i-1);
            cout<<right[i]<<endl;
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,a[i]+i+right[i]);    
        }
        for(int i=n-1;i>0;i--)
        {
            ans=max(ans,a[i]-i+left[i]);
        }
        return ans;
    }
};