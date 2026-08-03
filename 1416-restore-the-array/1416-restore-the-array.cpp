class Solution {
public:
int dp[100001];
int mod=1e9+7;
int func(int i,string &s,int k)
{
    if(i>=s.length())
    {
        return 1;
    }
    if(s[i]=='0')
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    long long num=0;
    long long ans=0;
    for(int end=i;end<s.size();end++)
    {
        num=num*10+(s[end]-'0');
        if(num>k)
        {
            break;
        }
        ans+=func(end+1,s,k);
        ans=ans%mod;
    }
    return dp[i]=ans;
}
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return func(0,s,k);
    }
};