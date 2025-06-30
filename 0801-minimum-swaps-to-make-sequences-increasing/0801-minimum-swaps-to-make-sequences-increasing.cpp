class Solution {
public:
int func(vector<int>& nums1, vector<int>& nums2,int index,int swapped, vector<vector<int>>&dp)
    {
        if(index==nums1.size())
        {
            return 0;
        }
        if(dp[index][swapped]!=-1)
        {
            return dp[index][swapped];
        }
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        //no swap
        if(swapped)
        {
            swap(prev1,prev2);
        }
        int count=INT_MAX;
       if(nums1[index]>prev1&&nums2[index]>prev2)
       {
          count=min(count,func(nums1,nums2,index+1,0,dp));
       }
       if(nums1[index]>prev2&&nums2[index]>prev1)
       {
        count=min(count,1+func(nums1,nums2,index+1,1,dp));
       }
       return dp[index][swapped]=count;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return func(nums1,nums2,1,0,dp);
    }
};