class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        vector<long long>left;
        int n=nums.size()/3;
        long long sum=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            pq.push(nums[i]);
        }
        left.push_back(sum);
        for(int i=n;i<2*n;i++)
        {
            sum+=nums[i];
            pq.push(nums[i]);
            sum-=pq.top();
            pq.pop();
            left.push_back(sum);
            // cout<<left.back();
        }
        vector<long long>right;
        priority_queue<int,vector<int>,greater<int>>pq1;
         sum=0;
        for(int i=3*n-1;i>=2*n;i--)
        {
            sum+=nums[i];
            pq1.push(nums[i]);
        }
        right.push_back(sum);
        for(int i=2*n-1;i>=n;i--)
        {
            sum+=nums[i];
            pq1.push(nums[i]);
            sum-=pq1.top();
            pq1.pop();
            right.push_back(sum);
            // right.back();
        }
        long long res=LLONG_MAX;
        // cout<<left.size()<<right.size();
        for(int i=0;i<left.size();i++)
        {
            // cout<<left[i];
            res=min(res,left[i]-right[n-i]);
        }
        return res;
    }
};