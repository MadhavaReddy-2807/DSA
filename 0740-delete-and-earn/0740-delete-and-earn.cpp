class Solution {
public:
unordered_map<int,int>mp;
unordered_map<int,int>dp;
int func(int num)
{
    if(num<=0)
    {
        return 0;
    }
    if(dp.find(num)!=dp.end())
    {
        return dp[num];
    }
    int take=func(num-2)+mp[num]*num;
    int nottake=func(num-1);
    return dp[num]=max(take,nottake);
}
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        for(auto it:nums)
        {
            mp[it]++;
        }
        return func(maxi);
    }
};