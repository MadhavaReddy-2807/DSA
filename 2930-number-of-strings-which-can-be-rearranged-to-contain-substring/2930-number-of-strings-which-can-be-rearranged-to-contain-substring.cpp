class Solution {
public:
const int mod=1e9+7;
vector<vector<vector<vector<int>>>>dp;
long long  func(int n,int index,int e=0,int l=0,int t=0)
{
    if(index==n)
    {
        if(e>=2&&l>=1&&t>=1)
        {
            return 1;
        }
        return 0;
    }
    if(dp[index][e][l][t]!=-1)
    {
        return dp[index][e][l][t];
    }
long long ways=0;
  for(int i=0;i<26;i++)
  {
      if(i==4&&e<2)
      {
        ways+=func(n,index+1,e+1,l,t);
        ways=ways%mod;
      }
      else if(i==11&&l<1)
      {
        ways+=func(n,index+1,e,l+1,t);
                ways=ways%mod;

      }
      else if(i==19&&t<1)
      {
        ways+=func(n,index+1,e,l,t+1);
                ways=ways%mod;

      }
      else
      {
        ways+=func(n,index+1,e,l,t);
                ways=ways%mod;

      }
  }
  return dp[index][e][l][t]=ways;
}
    int stringCount(int n) {
        dp.resize(n+1,vector<vector<vector<int>>>(3,vector<vector<int>>(2,vector<int>(2,-1))));
      return func(n,0);
    }
};