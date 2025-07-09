class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])
            {
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        vector<int>dp(a.size(),1);
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int h1=a[i][1];
                int h2=a[j][1];
                int l1=a[i][0];
                int l2=a[j][0];
                if(l2>l1&&h2>h1)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};