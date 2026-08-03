class Solution {
public:
vector<long long>pre;
int dp[501][501];
    long long func(int i,int j,vector<int>&nums)
    {
        if(i==j||i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long ans=INT_MIN;
        for(int k=i+1;k<=j;k++)
        {
            long long  left=pre[k-1]-((i-1>=0)?pre[i-1]:0);
            long long  right=pre[j]-((k-1>=0)?pre[k-1]:0);
            if(left<right)
            {
                ans=max(ans,left+func(i,k-1,nums));
            }
            else if(right<left)
            {
                ans=max(ans,right+func(k,j,nums));
            }
            else
            {
                ans=max(ans,left+func(i,k-1,nums));
                ans=max(ans,right+func(k,j,nums));
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        pre.resize(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        return func(0,nums.size()-1,nums);
    }
};