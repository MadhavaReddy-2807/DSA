class Solution {
public:
map<char,int>mp;
 int dp[1000][5][2000];
int mod=1e9+7;
int func(vector<int>&s,int index,int prev,int sum)
{
    if(index==s.size())
    {
        return sum>0;
    }
    if(dp[index][prev+1][sum+1000]!=-1)
    {
        return dp[index][prev+1][sum+1000];
    }
    long long ans=0;
   for(int i=0;i<3;i++)
   {
    if(i!=prev)
    {
       if(s[index]==i)
       {
         ans+=func(s,index+1,i,sum);
         ans=ans%mod;
       }    
       else if(i==(s[index]+1)%3)
       {
         ans+=func(s,index+1,i,sum+1);
          ans=ans%mod;
       }
       else
       {
        ans+=func(s,index+1,i,sum-1);
         ans=ans%mod;
       }
    }
   }
   return dp[index][prev+1][sum+1000]=ans;
}
    int countWinningSequences(string s) {
    mp['E']=0;
    mp['F']=1;
    mp['W']=2;
    memset(dp,-1,sizeof(dp));
    vector<int>arr(s.length());
    for(int i=0;i<s.length();i++)
    {
        arr[i]=mp[s[i]];
    }
    int sum=0;
    return func(arr,0,-1,0);
    }
};