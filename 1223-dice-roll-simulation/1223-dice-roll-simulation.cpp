class Solution {
public:
long long  mod=1e9+7;
int dp[5100][10][16];
  long long  func(int n,vector<int>&nums,int prev,int len)
  {
     if(n==0)
     {
        return 1;
     }
     long long ans=0;
     if(dp[n][prev+1][len]!=-1)
     {
        return dp[n][prev+1][len];
     }
     for(int i=0;i<6;i++)
     {
        if(i==prev&&len==nums[i])
        {
            continue;
        }
        if(i==prev&&len<nums[i])
        {
            ans+=func(n-1,nums,prev,len+1);
        }
        else
        {
            ans+=func(n-1,nums,i,1); 
        }
     }
     return dp[n][prev+1][len]=ans%mod;
  }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return func(n,rollMax,-1,0);
    }
};