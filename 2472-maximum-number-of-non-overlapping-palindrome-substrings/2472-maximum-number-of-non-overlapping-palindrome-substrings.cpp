class Solution {
public:
vector<vector<int>>ispalin;
vector<int>dp;
int func(int index,string &s,int k)
{
    if(index>=s.length())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int ways=func(index+1,s,k);
    for(int i=index+k-1;i<s.length();i++)
    {
        if(ispalin[index][i])
        {
            ways=max(ways,1+func(i+1,s,k));
        }
    }
    return dp[index]=ways;

}
    int maxPalindromes(string s, int k) {
        dp.resize(s.length()+1,-1);
        ispalin.resize(s.length()+1,vector<int>(s.length()+1,0));
        for(int len=1;len<=s.length();len++)
        {
            for(int i=0;i+len-1<s.length();i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                {
                    if(len<=2)
                    {
                        ispalin[i][j]=1;
                    }
                    else
                    {
                        ispalin[i][j]=ispalin[i+1][j-1];
                    }
                }
            }
        }
        return func(0,s,k);
    }
};