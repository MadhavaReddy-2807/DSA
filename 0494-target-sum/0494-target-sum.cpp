class Solution {
public:
map<pair<int,int>,int>mp;
int func(int index,int sum,vector<int>&nums,int target)
{
    if(index==nums.size())
    {
        return sum==target;
    }
    if(mp.find({index,sum})!=mp.end())
    {
        return mp[{index,sum}];
    }
    int x=func(index+1,sum+nums[index],nums,target);
    int t=func(index+1,sum-nums[index],nums,target);
    return mp[{index,sum}]=x+t;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0,0,nums,target);
    }
};