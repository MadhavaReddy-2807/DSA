class Solution {
public:
int req;
vector<vector<int>>dp;
int func(int index,vector<int>&nums,int k,int sum,int mask)
{
    if(k==0)
    {
        return 1;
    }
    if(sum==0)
    {
        return func(0,nums,k-1,req,mask);
    }
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[mask][k]!=-1)
    {
        return dp[mask][k];
    }
    int x=func(index+1,nums,k,sum,mask);
    int y=0;
    if(nums[index]<=sum)
    {
        if(!((mask>>index)&1))
        {
            y=func(index+1,nums,k,sum-nums[index],mask|(1<<index));
        }
    }
    return dp[mask][k]=x||y;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        dp.resize(1<<nums.size(),vector<int>(k+1,-1));
        req=tot/k;
        if(tot%k!=0)
        {
            return 0;
        }
        return func(0,nums,k,req,0);
    }
};