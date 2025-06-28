class Solution {
public:
    unordered_set<int> s;
    int func(string s1, string s2, int i, int j,vector<vector<int>>&dp) {
        if (j == 0) {
            int count=0;
            // cout<<i<<j;
           for(int k=0;k<i;k++)
               {
                   if(s.find(k) != s.end())
                   {
                       count++;
                   }
               }
            cout<<count;
            return count;
        }
        if (i == 0) {
            return INT_MIN;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int x = INT_MIN;
        if (s1[i - 1] == s2[j - 1]) {
            x = max(func(s1, s2, i - 1, j - 1,dp), x);
            if (s.find(i-1) != s.end()) {
                x = max(x, 1 + func(s1, s2, i - 1, j,dp));
            }
        }
        else
        {
           if (s.find(i-1) != s.end()) {
                x = max(x, 1 + func(s1, s2, i - 1, j,dp));
            } 
            else
           {
               x=max(x,func(s1,s2,i-1,j,dp));
           }
        }
        return dp[i][j]=x;
    }
    int maxRemovals(string source, string pattern, vector<int>& a) {
        s.insert(a.begin(), a.end());
        int m=source.length();
        int n=pattern.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(source, pattern, source.length(), pattern.length(),dp);
    }
};