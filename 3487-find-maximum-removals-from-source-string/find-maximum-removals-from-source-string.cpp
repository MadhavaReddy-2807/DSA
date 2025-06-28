#define ll long long 
class Solution {
public:
    long long solve(int s,int p,string&source,string&pattern,vector<bool>&isthere,vector<vector<int>>&dp)
    {
        if(p == pattern.size())
            return 0;
            
        else if(s == source.size())
            return INT_MAX;

        if(dp[s][p] != -1)
        {
            return dp[s][p];
        }
        if(source[s] == pattern[p])
        {
            if(isthere[s])
            {
                ll cand1 = 1LL + solve(s+1,p+1,source,pattern,isthere,dp);
                ll cand2 = solve(s+1,p,source,pattern,isthere,dp);
                ll ans = min(cand1,cand2);
                dp[s][p] = ans;
                return ans;
            }
            else
            {
                ll ans = solve(s+1,p+1,source,pattern,isthere,dp);
                dp[s][p] = ans;
                return ans;
            }
        }
        else
        {
            ll ans = solve(s+1,p,source,pattern,isthere,dp);
            dp[s][p] = ans;
            return ans;
        }
        return 0;
        
    }
    int maxRemovals(string source, string pattern, vector<int>& target) {
        int n = source.size();
        int p = pattern.size();
        vector<bool>isthere(n,false);
        for(auto&it:target)
        {
            isthere[it] = true;
        }
        vector<vector<int>>dp(n,vector<int>(p,-1));
        ll ans = solve(0,0,source,pattern,isthere,dp);
        return (ll)target.size() - ans;
    }
};