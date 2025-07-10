class Solution {
public:
long long dp[100][2][15];
const int mod=1e9+7;
long long func(string s,int index,int tight,int prev)
{
    if(index>=s.length())
    {
        return 1;
    }
    if(dp[index][tight][prev+1]!=-1)
    {
        return dp[index][tight][prev+1];
    }
    int limit=tight==1?s[index]-'0':9;
    long long  ways=0;
    for(int i=0;i<=limit;i++)
    {
        int newtight=tight&&(i==limit);
        if(prev==-1&&i==0)
        {
          ways+=func(s,index+1,newtight,-1);
          ways=ways%mod;
        }
        else if(prev==-1)
        {
            ways+=func(s,index+1,newtight,i);
            ways=ways%mod;
        }
        else
        {
            if(abs(prev-i)==1)
            {
              ways+=func(s,index+1,newtight,i);
              ways=ways%mod;
            }
        }
    }
    return dp[index][tight][prev+1]=ways;
}
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        low[low.length()-1]=low[low.length()-1]-1;
        // long long  x=stol(low);
        // low=to_string(x-1);
        long long a=func(high,0,1,-1);
        memset(dp,-1,sizeof(dp));
        long long b=func(low,0,1,-1);
        return (a-b+mod)%mod;
        
    }
};