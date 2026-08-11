class Solution {
public:
    long long appealSum(string s) {
        vector<vector<long long>>dp(s.length()+1,vector<long long>(27,0));
        dp[0][s[0]-'a']++;
        long long res=1;
        for(int i=1;i<s.length();i++)
        {
            for(int ch=0;ch<26;ch++)
            {
                if(ch==(s[i]-'a'))
                {
                   dp[i][ch]=i+1;
                }
                else
                {
                    dp[i][ch]=dp[i-1][ch];
                }
             res+=dp[i][ch];
            }
        }
        return res;
    }
};