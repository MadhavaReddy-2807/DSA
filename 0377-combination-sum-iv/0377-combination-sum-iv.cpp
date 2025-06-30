class Solution {
public:
unordered_map<int,int>mp;
    int func(vector<int>nums,int target,int sum)
    {
        if(target==sum)
        {
            return 1;
        }
        int count=0;
        if(mp.count(sum))
        {
            return mp[sum];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=target)
            {
                count+=func(nums,target,sum+nums[i]);
            }
        }
        return mp[sum]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return func(nums,target,0);
    }
};