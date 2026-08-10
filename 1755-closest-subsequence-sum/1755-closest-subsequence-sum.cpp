class Solution {
public:
vector<long long>generate(vector<int>&nums)
{
    int n=nums.size();
    vector<long long>result;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if((mask>>i)&1)
            {
                sum+=nums[i];
            }
        }
        result.push_back(sum);
    }
    return result;
}
    int minAbsDifference(vector<int>& nums, int goal) {
        /*(sum1+sums2)-goal min;
        sum1-(goal-sum2);
          need to find closer value of (goal-sum2) can be done using lower_bound
        */
        int n=nums.size();
        vector<int>first(nums.begin(),nums.begin()+(n/2));
        vector<int>second(nums.begin()+(n/2),nums.end());
        vector<long long>sum1=generate(first);
        vector<long long>sum2=generate(second);
        // sort(sum1.begin(),sum1.end());
        sort(sum2.begin(),sum2.end());
        long long ans=INT_MAX;
        for(int i=0;i<sum1.size();i++)
        {
            auto it=lower_bound(sum2.begin(),sum2.end(),goal-sum1[i]);
            if(it!=sum2.end())
            {
                ans=min(ans,abs(*it-(goal-sum1[i])));
            }
            if(it!=sum2.begin())
            {
                it--;
                ans=min(ans,abs(*it-(goal-sum1[i])));
            }
        }
        return ans;
    }
};