class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
       int neg=0;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]<0)
        {
            neg++;
        }
       }
        int n=nums.size();
        if(neg==0)
        {
            return accumulate(nums.begin(),nums.end(),0LL);
        }
        else if(neg==n)
        {
            return *max_element(nums.begin(),nums.end());
        }
        if(k==0)
        {
            long long maxi=nums[0];
            long long maxsum=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                maxi=max<long long>(maxi+nums[i],nums[i]);
                maxsum=max(maxsum,maxi);
            }
            return maxsum;
        }
        vector<vector<long long>>subarraysum(n,vector<long long>(n,0));
        vector<vector<long long>>arr1(n,vector<long long>(n,0));
        vector<vector<long long>>arr2(n,vector<long long>(n,0));
     for(int i=0;i<n;i++)
     {
       long long sum=0;
       for(int j=i;j<n;j++)
       {
        sum+=nums[j];
       subarraysum[i][j]=sum;
       }
     }
     for(int i=0;i<n;i++)
     {
     priority_queue<int>pq;
     long long sum=0;
        for(int j=i;j<n;j++)
        {
            if(nums[j]<0)
            {
                if(pq.size()<k)
                {
                    sum+=nums[j];
                    pq.push(nums[j]);
                }
                else
                {
                    if(pq.top()>nums[j])
                    {
                        sum-=pq.top();
                        pq.pop();
                        sum+=nums[j];
                        pq.push(nums[j]);
                    }
                }
            }
            arr1[i][j]=sum;
        }
     }
     for(int i=0;i<n;i++)
     {
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]>0)
            {
                if(pq.size()<k)
                {
                    sum+=nums[j];
                    pq.push(nums[j]);
                }
                else
                {
                    if(pq.top()<nums[j])
                    {
                        sum-=pq.top();
                        pq.pop();
                        sum+=nums[j];
                        pq.push(nums[j]);
                    }
                }
            }
        }
        arr2[i][n-1]=sum;
        for(int j=n-2;j>=i;j--)
        {
             if(nums[j+1]>0)
            {
                if(pq.size()<k)
                {
                    sum+=nums[j+1];
                    pq.push(nums[j+1]);
                }
                else
                {
                    if(pq.top()<nums[j+1])
                    {
                        sum-=pq.top();
                        pq.pop();
                        pq.push(nums[j+1]);
                        sum+=nums[j+1];
                    }
                }
            }
            arr2[i][j]=sum;
        }
     }
      int result=INT_MIN;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
            result=max<long long>(result,subarraysum[i][j]-arr1[i][j]+arr2[i][j]);
        }
      }
      return result;
    }
};