int dp[101][101][27][101];
class Solution {
public:
int func(string &s,int i,int k,int prev,int len)
{
    if(i>=s.length())
    {
        if(len==0)
        {
            return 0;
        }
        if(len==1)
        {
            return 1;
        }
       string rough=to_string(len);
       return 1+rough.length();
    }
    if(dp[i][k][prev+1][len]!=-1)
    {
        return dp[i][k][prev+1][len];
    }
    //take;
    int res=INT_MAX;
    int curr=s[i]-'a';
    if(curr==prev)
    {
        res=min(res,func(s,i+1,k,prev,len+1));
    }
    else
    {
        int count=0;
        if(len==0)
        {
            count=0;
        }
       else if(len==1)
        {
            count=1;
        }
        else
        {
            string rough=to_string(len);
            count=1+rough.length();
        }
       res=min(res,count+func(s,i+1,k,curr,1));
    }
    //delele
    if(k!=0)
    {
        res=min(res,func(s,i+1,k-1,prev,len));
    }
    return dp[i][k][prev+1][len]=res;
}
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return func(s,0,k,-1,0);
    }
};