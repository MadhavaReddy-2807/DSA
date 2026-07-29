class Solution {
public:
int dp[10][3][3];
int func(string &s,int index,vector<int>&digits,int tight,int start)
{
    if(s.length()==index)
    {
        return start;
    }
    long long ans=0;
    if(dp[index][tight][start]!=-1)
    {
        return dp[index][tight][start];
    }
    if(!start)
    {
        ans+=func(s,index+1,digits,0,start);
    }
    int limit=tight?(s[index]-'0'):9;
    for(int i=0;i<digits.size();i++)
    {
        if(digits[i]>limit)
        {
            continue;
        }
        int ntight=tight&&(limit==digits[i]);
        ans+=func(s,index+1,digits,ntight,1);
    }
    return dp[index][tight][start]=ans;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        vector<int>nums;
        memset(dp,-1,sizeof(dp));
        for(auto x:digits)
        {
            nums.push_back(stoi(x));
        }
        return func(s,0,nums,1,0);
    }
};