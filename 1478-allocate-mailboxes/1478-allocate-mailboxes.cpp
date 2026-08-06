class Solution {
public:
int dp[102][102];
    long  long func(vector<vector<int>>&dist,int i,int k,vector<int>&nums)
    {
        if(i>=nums.size())
        {
            if(k!=0)
            {
                return INT_MAX;
            }
            return 0;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        if(k==1)
        {    
            return dp[i][k]=dist[i][nums.size()-1];
        }
        else
        {
            long long ans=INT_MAX;
             for(int j=i;j<nums.size();j++)
             {
                 ans=min(ans,1LL*dist[i][j]+func(dist,j+1,k-1,nums));
             }
             return dp[i][k]=ans;
        }
        return dp[i][k]=-1;
    }
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        memset(dp,-1,sizeof(dp));
        sort(houses.begin(),houses.end());
        vector<vector<int>>medians(n,vector<int>(n));
        vector<vector<int>>dist(n,vector<int>(n));
       for(int i=0;i<n;i++)
       {
         for(int j=i;j<n;j++)
         {
            medians[i][j]=houses[(i+j)/2];
         }
       }
       for(int i=0;i<n;i++)
       {
        for(int j=i;j<n;j++)
        {
            int sum=0;
             for(int k=i;k<=j;k++)
             {
                sum+=abs(houses[k]-medians[i][j]);
             }
             dist[i][j]=sum;
        }
       }
       if(n<=k)
       {
        return 0;
       }
       return func(dist,0,k,houses);
    }
};