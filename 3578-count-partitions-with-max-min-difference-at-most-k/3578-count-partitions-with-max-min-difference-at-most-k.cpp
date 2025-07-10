class Solution {
public:
const long long  mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        long long  n=nums.size();
        vector<long long >dp(n+1,0);
        vector<long long >pre(n+1,0);
        pre[0]=1;
        dp[0]=1;
        long long  r=0;
        long long  l=0;
        multiset<long long >mp;
        while(r<nums.size())
        {
            mp.insert(nums[r]);
            while(*mp.rbegin()-*mp.begin()>k)
            {
                mp.erase(mp.find(nums[l]));
                l++;
            }
            dp[r+1]=(pre[r]-(l-1>=0?pre[l-1]:0))%mod;
            pre[r+1]=(pre[r]+dp[r+1])%mod;
            r++;
        }
        return dp[n]%mod;
    }
};