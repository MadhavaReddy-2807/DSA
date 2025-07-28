class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                k=i;
            }
        }
        if(k==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int last=k;
        for(int i=k+1;i<nums.size();i++)
        {
            if(nums[k]<nums[i])
            {
                last=i;
            }
        }
        swap(nums[last],nums[k]);
        reverse(nums.begin()+k+1,nums.end());

    }
};