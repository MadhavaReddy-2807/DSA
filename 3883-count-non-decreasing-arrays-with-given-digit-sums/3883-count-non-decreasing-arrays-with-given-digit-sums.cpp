class Solution {
public:
int mod=1e9+7;
    int countArrays(vector<int>& a) {
        vector<int>digisum(5002,0);
        for(int i=1;i<=5000;i++)
        {
            int x=i;
            while(x)
            {
                digisum[i]+=(x%10);
                x=x/10;
            }
        }
        int n=a.size();
        vector<vector<int>>dp(n+2,vector<int>(5002,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            int pre=0;
            for(int j=0;j<=5000;j++)
            {
                pre=(pre+dp[i-1][j])%mod;
                if(digisum[j]==a[i-1])
                {
                    dp[i][j]=pre;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=5000;i++)
        {
            ans=(ans+dp[n][i])%mod;
        }
        return ans;
    }
};