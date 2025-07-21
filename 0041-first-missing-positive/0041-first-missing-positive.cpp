class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int found=false;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            return 1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]<1)
            {
                nums[i]=1;
            }
            if(nums[i]>n)
            {
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            while((nums[i]!=nums[nums[i]-1]))
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if((i+1)!=nums[i])
            {
                return (i+1);
            }
        }
        return n+1;
    }
};