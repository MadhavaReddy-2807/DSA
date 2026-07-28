class Solution {
public:
long long  dp[101][3][3][11][3];
int mod=1e9+7;
  int func(string& low,string& high,int index,int ltight,int rtight,int prev,int start)
  {
    if(index==high.size())
    {
        return start;
    }
    int llimit=ltight?low[index]-'0':0;
    int rlimit=rtight?high[index]-'0':9;
    long long ans=0;
    if(dp[index][ltight][rtight][prev+1][start]!=-1)
    {
        return dp[index][ltight][rtight][prev+1][start];
    }
    for(int i=llimit;i<=rlimit;i++)
    {
        int nltight=(ltight)&&(low[index]-'0'==i);
        int nrtight=(rtight)&&(high[index]-'0'==i);
        if(prev==-1)
        {
            if(i!=0)
            {
                ans+=func(low,high,index+1,nltight,nrtight,i,1);
                ans=ans%mod;

            }
            else
            {
                ans+=func(low,high,index+1,nltight,nrtight,prev,0);
                ans=ans%mod;

            }
        }
        else
        {
            if(abs(prev-i)==1)
            {
              ans+=func(low,high,index+1,nltight,nrtight,i,1);
              ans=ans%mod;
            }
        }
    }
    return dp[index][ltight][rtight][prev+1][start]=ans%mod;
  }
    int countSteppingNumbers(string low, string high) {
        while(low.size()!=high.size())
        {
            low='0'+low;
        }
        memset(dp,-1,sizeof(dp));
        return func(low,high,0,1,1,-1,0);
    }
};