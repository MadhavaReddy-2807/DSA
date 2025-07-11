class Solution {
public:
int dp[11][2][2][1<<10];
int func(int index,int allzeros,int tight,string s,int mask)
{
    if(index>=s.length())
    {
        return 1;
    }
    int limit=tight==1?s[index]-'0':9;
    int count=0;
    if(dp[index][allzeros][tight][mask]!=-1)
    {
        return dp[index][allzeros][tight][mask];
    }
    for(int i=0;i<=limit;i++)
    {
        if(allzeros==0&&((mask>>i)&1))
        {
            continue;
        }
        int new_tight=tight&&(i==limit);
        int newzero=allzeros&&(i==0);
        int new_mask=(newzero==1)?mask:mask|(1<<i);
      count+=func(index+1,newzero,new_tight,s,new_mask);
    }
    return dp[index][allzeros][tight][mask]=count;
}
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
       return n-func(0,1,1,s,0)+1;
}
};