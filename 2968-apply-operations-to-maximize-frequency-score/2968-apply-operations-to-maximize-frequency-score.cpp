class Solution {
public:
 int func(int len,vector<int>&nums,vector<long long>&pre,long long k)
 {
     long long  l=0;
     long long r=len-1;
     while(r<nums.size())
     {
        long long mid=(l+r)/2;
        long long ops=(mid-l)*nums[mid]-((mid!=0)?pre[mid-1]:0)+((l!=0)?pre[l-1]:0)+pre[r]-pre[mid]-(r-mid)*nums[mid];
        if(ops<=k)
        {
            return 1;
        }
        l++;
        r++;
     }
     return 0;
 }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        vector<long long>pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int l=1;
        int r=nums.size();
        int ans=1;
       while(l<=r)
       {
         int mid=(l+r)/2;
         if(func(mid,nums,pre,k))
         {
            ans=mid;
            l=mid+1;
         }
         else
         {
            r=mid-1;
         }
       }
       return ans;
    }
};