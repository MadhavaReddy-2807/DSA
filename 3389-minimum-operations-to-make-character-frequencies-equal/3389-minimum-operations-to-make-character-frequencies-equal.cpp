class Solution {
public:
int dp[26];
int func(int index,vector<int>&nums,int c)
{
    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    //2 options to remove the char completely or match with freq
    int res=INT_MAX;
    //option 1
    res=min(res,nums[index]+func(index+1,nums,c));
     if(nums[index]==c)
     {
        res=min(res,func(index+1,nums,c));
     }
    //option 2
     //case1 : if extra than req
     if(nums[index]>c)
     {
        int extra=nums[index]-c;
        res=min(res,extra+func(index+1,nums,c));
         //if next has requirment;
         if(index+1<26&&nums[index+1]<c)
         {
            int req=c-nums[index+1];
            if(extra>req)
            {
                res=min(res,extra+func(index+2,nums,c));
            }
            else
            {
                res=min(res,req+func(index+2,nums,c));
            }
         }
         else
         {
            res=min(res,extra+func(index+1,nums,c));
         }
     }
     else
     {
        int req = c - nums[index];
        res = min(res, req + func(index + 1, nums, c));
        if (index + 1 < 26 && nums[index + 1] < c) {
            int extra = c-nums[index+1];
            // cout<<req<<" "<<extra<<endl;;
            res = min(res, max(nums[index], extra) + func(index + 2, nums, c));
        }
     }
     return dp[index]=res;
    
}
    int makeStringGood(string s) {
       int res=INT_MAX;
       vector<int>mp(26,0);
       for(auto c:s)
       {
         mp[c-'a']++;
       }
    //    int res=INT_MAX;
       for(int i=1;i<=s.length();i++)
       {
        memset(dp,-1,sizeof(dp));
        res=min(res,func(0,mp,i));
       }
       return res;
       
    }
};