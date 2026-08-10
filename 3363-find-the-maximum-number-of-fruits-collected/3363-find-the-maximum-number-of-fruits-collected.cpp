class Solution {
public:
int dp1[1001][1001];
int dp2[1001][1001];
   long long f2(int i,int j,int n,vector<vector<int>>&fruits)
   {
    if(i < 0 || i >= n || j < 0 || j >= n)
        return  INT_MIN;
    if(i==n-1&&j==n-1)
    {
        return 0;
    }
    if(dp1[i][j]!=-1)
    {
        return dp1[i][j];
    }
    if(i>=j)
    {
        return INT_MIN;
    }
    long long ans=INT_MIN;
     ans=max(ans,f2(i+1,j-1,n,fruits)+fruits[i][j]);
     ans=max(ans,f2(i+1,j,n,fruits)+fruits[i][j]);
     ans=max(ans,f2(i+1,j+1,n,fruits)+fruits[i][j]);
     return dp1[i][j]=ans;
   }
  long long f3(int i,int j,int n,vector<vector<int>>&fruits)
   {
    if(i < 0 || i >= n || j < 0 || j >= n)
     return  INT_MIN;
    if(i==n-1&&j==n-1)
    {
        return 0;
    }
    if(dp2[i][j]!=-1)
    {
        return dp2[i][j];
    }
    if(i<=j)
    {
        return INT_MIN;
    }
    long long ans=INT_MIN;
     ans=max(ans,f3(i-1,j+1,n,fruits)+fruits[i][j]);
     ans=max(ans,f3(i,j+1,n,fruits)+fruits[i][j]);
     ans=max(ans,f3(i+1,j+1,n,fruits)+fruits[i][j]);
     return dp2[i][j]=ans;
   }
   
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int count=0;
        int n=fruits.size();
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        for(int i=0;i<fruits.size();i++)
        {
            count+=fruits[i][i];
        }
        count+=f2(0,n-1,n,fruits);
        count+=f3(n-1,0,n,fruits);
        return count;
    }
};