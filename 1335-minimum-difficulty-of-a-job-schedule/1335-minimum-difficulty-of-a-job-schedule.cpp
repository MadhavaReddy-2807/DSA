class Solution {
public:
int dp[301][12];
long long func(vector<int>&jobs,int d,int index)
{
    if(index==jobs.size())
    {
        if(d==0)
        {
            return 0;
        }
        return INT_MAX;
    }
    if(d==0)
    {
        return INT_MAX;
    }
    if(dp[index][d]!=-1)
    {
        return dp[index][d];
    }
    long long ans=INT_MAX;
    long long maxi=INT_MIN;
    for(int i=index;i<jobs.size();i++)
    {
        maxi=max<long long>(maxi,jobs[i]);
        ans=min<long long>(ans,maxi+func(jobs,d-1,i+1));
    }
    return dp[index][d]=ans;

}
    int minDifficulty(vector<int>& jobs, int d) {
        memset(dp,-1,sizeof(dp));
        if(jobs.size()==d)
        {
            return accumulate(jobs.begin(),jobs.end(),0LL);
        }
        else if(jobs.size()<d)
        {
            return -1;
        }
        return func(jobs,d,0);
    }
};