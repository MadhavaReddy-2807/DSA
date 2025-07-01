class Solution {
public:
int dp[301];
 unordered_set<string>st;
 int func(string s,int index)
 {
    if(index==s.length())
    {
        return true;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    for(int i=index;i<s.length();i++)
    {
        string  rough=s.substr(index,i-index+1);
        if(st.find(rough)!=st.end())
        {
            if(func(s,i+1))
            {
                return dp[index]=true;
            }
        }
    }
    return dp[index]=false;
 }
    bool wordBreak(string s, vector<string>& wordDict) {
   st.insert(wordDict.begin(),wordDict.end());
   memset(dp,-1,sizeof(dp));
      return func(s,0);
    }
};