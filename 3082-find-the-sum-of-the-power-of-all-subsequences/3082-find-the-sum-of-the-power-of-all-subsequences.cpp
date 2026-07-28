class Solution {
public:
int mod=1e9+7;
int dp[101][101][101];
long long power(long long  a,long long  b)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}
long long func(vector<int>&nums,int k,int i,int len)
{
    if(i==nums.size())
    {
        if(k==0)
        {
            return power(2,nums.size()-len);
        }
        return 0;
    }
    if(dp[k][i][len]!=-1)
    {
        return dp[k][i][len];
    }
    //nottake
    long long x=func(nums,k,i+1,len);
    //take
    long long y=0;
    if(nums[i]<=k)
    {
        y+=func(nums,k-nums[i],i+1,len+1);
    }
    return dp[k][i][len]=(x+y)%mod;
}
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
       long long result=func(nums,k,0,0);
       return result;
    }
};