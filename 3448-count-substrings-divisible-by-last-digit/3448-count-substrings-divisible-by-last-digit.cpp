class Solution {
public:
    long long countSubstrings(string s) {
        vector<vector<vector<long long >>>dp(s.length()+1,vector<vector<long long>>(11,vector<long long>(10,0)));
        for(int i=1;i<=9;i++)
        {
            int rem=(s[0]-'0')%i;
            dp[0][i][rem]+=1;
        }
        for(int index=1;index<s.length();index++)
        {
            for(int i=1;i<=9;i++)
            {
                int num=s[index]-'0';
                int rem=(num)%i;
                dp[index][i][rem]+=1;
             for (int prevRem = 0; prevRem < i; prevRem++) {
                int newRem = (prevRem * 10 + num) % i;
                dp[index][i][newRem] += dp[index - 1][i][prevRem];
                  }
            }
        }
        long long result=0;
        for(int i=0;i<s.length();i++)
        {
            int num=s[i]-'0';
            result+=dp[i][num][0];
        }
        return result;
    }
};