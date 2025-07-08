class Solution {
public:
int find(vector<int>&nums,int val)
{
    int l=0;
    int r=nums.size()-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]>val)
        {
            ans=mid;
            r=mid-1;
        }
        else if(nums[mid]==val)
        {
            return mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(int i=0;i<nums.size();i++)
        {
            int x=find(lis,nums[i]);
            if(x==-1)
            {
                lis.push_back(nums[i]);
            }
            else
            {
                lis[x]=nums[i];
            }
        }
        return lis.size();
    }
};