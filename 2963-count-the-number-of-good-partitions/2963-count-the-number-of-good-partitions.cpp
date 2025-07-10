class Solution {
public:
unordered_map<int,int>first;
unordered_map<int,int>last;
const int mod=1e9+7;
int func(int a,int b)
{
    long long  res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*1LL*a)%mod;
        }
        a=(1LL*a*a)%mod;
        b=b/2;
    }
    return res;
}
    int numberOfGoodPartitions(vector<int>& nums) {
      for(int i=0;i<nums.size();i++)
      {
            if(first.find(nums[i])==first.end())
            {
                first[nums[i]]=i;
            }
      }
      for(int i=nums.size()-1;i>=0;i--)
      {
        if(last.find(nums[i])==last.end())
        {
            last[nums[i]]=i;
        }
      }
      int count=0;
      int p=0;
      for(int i=0;i<nums.size();i++)
      {
        int start=i;
        int end=last[nums[i]];
        for(int j=start;j<end;j++)
        {
            end=max(end,last[nums[j]]);
        }
        i=end;
        // cout<<p<<endl;
        p++;
      }
      long long res=func(2,p-1);
      return res;
    }
};