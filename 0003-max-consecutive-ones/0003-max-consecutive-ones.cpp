class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int r=0;
        int count=INT_MIN;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                count=max(count,r-l);
                r=r+1;
                l=r;
            }
            else
            {
                r++;
            }
        }
        count=max(count,r-l);
        return count;

    }
};