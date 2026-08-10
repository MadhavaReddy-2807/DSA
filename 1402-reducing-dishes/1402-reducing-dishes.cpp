class Solution {
public:
long long dp[501][501];
long long  func(int index,int prev,vector<int>&nums)
{
    if(index==nums.size())
    {
        return 0;
    }
    if(dp[index][prev]!=-1)
    {
        return dp[index][prev];
    }
    long long ans=INT_MIN;
    //not take
    ans=max(ans,func(index+1,prev,nums));
    //take;
    ans=max(ans,1LL*nums[index]*(prev+1)+func(index+1,prev+1,nums));
    return dp[index][prev]=ans;
}
    int maxSatisfaction(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return func(0,0,nums);
    }
};