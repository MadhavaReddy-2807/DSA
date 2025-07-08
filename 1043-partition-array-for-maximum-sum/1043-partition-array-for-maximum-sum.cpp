class Solution {
public:
   int func(vector<int>&arr,int index,int k,vector<int>&dp)
   {
    if(index>=arr.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int result=INT_MIN;
    int maxi=arr[index];
    for(int i=0;i<k;i++)
    {
        if((index+i)<arr.size())
        {

        maxi=max(maxi,arr[index+i]);
        result=max(result,(i+1)*maxi+func(arr,index+i+1,k,dp));
        }
    }
    return dp[index]=result;
   }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return func(arr,0,k,dp);
    }
};